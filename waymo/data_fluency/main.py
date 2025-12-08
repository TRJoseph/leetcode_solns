import pandas as pd
import numpy as np
import os
import matplotlib.pyplot as plt


def cleanRides(rides: pd.DataFrame) -> pd.DataFrame:
    rides['Date/Time'] = rides['Date/Time'].interpolate()
    rides = rides.dropna(subset=['Lat', 'Lon'])

    return rides 

def userFcn(rides : pd.DataFrame) -> pd.DataFrame:
    print(rides.head(10))
    print(rides.isna().sum())

    rides = cleanRides(rides)
    return rides

def main():
    rides = pd.read_csv('./uber-raw-data-apr14.csv')

    # Convert datetime column
    rides['Date/Time'] = pd.to_datetime(
        rides['Date/Time'], 
        format="%m/%d/%Y %H:%M:%S",
        errors='coerce'
    )

    # Sort by datetime
    rides = rides.sort_values('Date/Time')

    # ---- Introduce Missing Values Into the Dataset ----

    np.random.seed(42)  # for reproducibility
    n = len(rides)
    frac = 0.01  # 1% missing

    def insert_missing(colname):
        count = int(n * frac)
        idx = np.random.choice(rides.index, count, replace=False)
        rides.loc[idx, colname] = np.nan if colname != 'Date/Time' else pd.NaT

    # Missing values in raw columns
    insert_missing('Date/Time')
    insert_missing('Lat')
    insert_missing('Lon')
    insert_missing('Base')

    # ---- Recompute feature columns (missing values propagate naturally) ----

    # Show a small preview
    #print(rides.head(10))

    rides = userFcn(rides)

    rides['hour'] = rides['Date/Time'].dt.hour
    rides['day_of_week'] = rides['Date/Time'].dt.dayofweek
    rides['month'] = rides['Date/Time'].dt.month
    rides['Base'] = rides['Base'].fillna(rides['Base'].mode()[0])

    # print(rides.sample(10))
    # print(rides.isna().sum())

    #print(rides.shape[0])

    day_map = {0:'Mon', 1:'Tue', 2:'Wed', 3:'Thu', 4:'Fri', 5:'Sat', 6:'Sun'}
    day_counts = rides['day_of_week'].value_counts().sort_index()
    day_counts.index = day_counts.index.map(day_map)

    # print(day_counts)

    rides_per_hour = rides.groupby(['hour']).size()

    num_days = rides['Date/Time'].dt.date.nunique()
    average_rides_per_hour = rides_per_hour / num_days
    average_rides_per_hour = pd.DataFrame({'averageRidesPerHour' : average_rides_per_hour})
    # print(average_rides_per_hour.head())

    # print(average_rides_per_hour.max().iloc[0])

    # rides['day_of_week'] = rides['day_of_week'].map(day_map)

    # rides.groupby(['hour', 'day_of_week']).size()
    

    # now we may want to show the average rides per hour on a weekday versus a weekend
    #print(rides.groupby(['hour', 'day_of_week']).size().head(10))

    rides['is_weekend'] = rides['day_of_week'].apply(lambda x: 1 if x >= 5 else 0)
    average_rides_hour_weekend = rides.groupby(['hour', 'is_weekend']).mean().unstack()


    print(average_rides_hour_weekend.head())



    #average_rides_per_hour_weekday = rides.groupby(['hour', 'day_of_week']).agg(['mean'])


    # average_rides_per_hour['averageRidesPerHour'].hist(bins=10)
    # plt.xlabel("Average rides per hour")
    # plt.ylabel("Frequency")
    # plt.show()



if __name__ == "__main__":
    main()
