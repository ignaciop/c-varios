# mean_temps.py
# Calculates the mean temperature of each season in Toronto
# Elizabeth Patitsas; Dec 24, 2012

# Mean temperature in Toronto, on a month-by-month basis
# Source: http://en.wikipedia.org/wiki/Toronto#Climate
mean_temps = [-4.2, -3.2, 1.3, 7.6, 14.2, 19.2, 22.2, 21.3, 17.0, 10.6, 4.8, -0.9]

# Mean temperature of each season
NUM_SEASONS = 4
MONTHS_IN_SEASON = len(mean_temps) / NUM_SEASONS

# create a list, mean_seasonal, initialized to [0, 0, 0, 0]
mean_seasonal = [0]*NUM_SEASONS 

# Now we want to calculate the mean temperature in Toronto during
# each of the four seasons; note that mean_temps begins with January
curr_season = 0

for m in range(len(mean_temps)):
	# if we're at March (2), June (5), September (8) or December (11), update the season
	if (m+1) % MONTHS_IN_SEASON == 0:
		curr_season += 1
		# We use mod to restore the season to 0 after passing the alloted number of seasons in a year (i.e more then 1 year)
		curr_season %= NUM_SEASONS 
	
	# since we know how many months there are in a season, we can calculate the average as we go
	mean_seasonal[curr_season] += mean_temps[m] / MONTHS_IN_SEASON

# Finally, print each season's mean temp on a new line:
print("Mean seasonal temperatures in Toronto")

seasons = ["winter", "spring", "summer", "autumn"]

for s in range(len(seasons)):
	print(seasons[s], "(" + str(s) + "):", mean_seasonal[s], "deg C")