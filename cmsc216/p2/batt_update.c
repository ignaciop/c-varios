#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "batt.h"

int set_batt_from_ports(batt_t *batt) {
    int bfp = 1;
    
    if (batt != NULL) {
        if (BATT_VOLTAGE_PORT >= 0) {
            short batt_v = BATT_VOLTAGE_PORT >> 1;
            batt->mlvolts = batt_v;
            
            short batt_p = (batt_v - 3000) >> 3;
            
            if (batt_p < 0) {
                batt_p = 0;
            } else if (batt_p > 100) {
                batt_p = 100;
            }

            batt->percent = batt_p;
            
            const short mode_mask = 0x10;
            
            batt->mode = (BATT_STATUS_PORT & mode_mask) ? 1 : 2;
            
            bfp = 0;
        }
    }
    
    return bfp;
}

int set_display_from_batt(batt_t batt, int *display) {
    int dfb = 0;
    
    if (display != NULL) {
        *display ^= *display;
        
        const int digits_masks[10] = {0x3f, 0x6, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x7, 0x7f, 0x6f};
        const int batt_levels[6] = {0x0, 0x1, 0x3, 0x7, 0xf, 0x1f};
        const int blank = 0x0;
        
        int idx = -1;
        
        if (batt.percent < 5) {
            idx = 0;
        } else if (batt.percent >= 5 && batt.percent <= 29) {
            idx = 1;
        } else if (batt.percent >= 30 && batt.percent <= 49) {
            idx = 2;
        } else if (batt.percent >= 50 && batt.percent <= 69) {
            idx = 3;
        } else if (batt.percent >= 70 && batt.percent <= 89) {
            idx = 4;
        } else {
            idx = 5;
        }
        
        /* Set and put battery indicators to display bits in the corresponding place to further shifting */
        *display = (*display | batt_levels[idx]) << 7;
        
        if (batt.mode == 1) {
            /* Set and put digits to display bits in the corresponding place to further shifting */
            if (batt.percent == 100) {
                *display = (*display | digits_masks[1]) << 7;
                *display = (*display | digits_masks[0]) << 7;
                *display = (*display | digits_masks[0]) << 3;
            } else {
                *display = (*display | blank) << 7;
                
                int middle_digit = batt.percent / 10;
                int right_digit = batt.percent % 10;
            
                if (middle_digit != 0) {
                    *display = (*display | digits_masks[middle_digit]) << 7;
                } else {
                    *display = (*display | blank) << 7;
                }
            
                *display = (*display | digits_masks[right_digit]) << 3;
            }
            
            /* Set and put voltage indicator and decimal bits in the corresponding place */
            *display = (*display | 0x1);
        } else if (batt.mode == 2) {
            int left_digit = batt.mlvolts / 1000;
            int ld_mod = batt.mlvolts % 1000;
        
            int middle_digit = ld_mod / 100;
            int md_mod = ld_mod % 100;
            
            int right_digit = md_mod / 10;
            
            int rd_mod = md_mod % 10;
            
            if (rd_mod > 5) {
                right_digit += 1;
            } 
        
            /* Set and put digits to display bits in the corresponding place to further shifting */
            *display = (*display | digits_masks[left_digit]) << 7;
            *display = (*display | digits_masks[middle_digit]) << 7;
            *display = (*display | digits_masks[right_digit]) << 3;
            
            /* Set and put voltage indicator and decimal bits in the corresponding place */
            *display = (*display | 0x6);
        }
    }
    
    return dfb;
}

int batt_update(void) {
    int bup = 1;
    
    batt_t b;
    
    int bfp = set_batt_from_ports(&b);
    
    if (bfp == 0) {
        set_display_from_batt(b, &BATT_DISPLAY_PORT);
        
        bup = 0;
    }
    
    return bup;
}
