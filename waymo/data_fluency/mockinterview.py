import pandas as pd
import numpy as np

def parse_ts(x):
    for fmt in [
        "%Y-%m-%d %H:%M:%S",
        "%Y-%m-%d %H:%M",
        "%Y/%m/%d %H:%M:%S",
        "%Y-%m-%dT%H:%M:%SZ",
        "%m/%d/%Y %H:%M:%S",
        "%m/%d/%y %H:%M:%S",
    ]:
        try:
            return pd.to_datetime(x, format=fmt)
        except:
            pass
    return pd.NaT

def imputeVals(df: pd.DataFrame, subjectCol: str, subject: str, targetCol: str, imputeMethod = "mean") -> pd.DataFrame:
    lidar_point_car_mask = (df[subjectCol] == subject) & df[targetCol].isna()
    lidar_point_car_mask_filtered = (df[subjectCol] == subject) & ~(df[targetCol].isna())
    df.loc[lidar_point_car_mask, targetCol] = df.loc[lidar_point_car_mask_filtered, targetCol].mean()
    return df

def main():
    df = pd.read_csv("waymo/data_fluency/mockinterview.csv")


    df['timestamp'] = df['timestamp'].apply(parse_ts)


    df = df[df["object_type"] != "Unknown"]
    df.dropna(subset=["object_id"], inplace=True)
    df.dropna(subset=["distance_m"], inplace=True)
    df.dropna(subset=["confidence"], inplace=True)

    df = imputeVals(df, "object_type", "Car", "lidar_point_count")
    df = imputeVals(df, "object_type", "Pedestrian", "velocity_mps")
    df = imputeVals(df, "object_type", "Pedestrian", "lidar_point_count")

    print(df.info())
    print(df.head(10))

    print(df.isna().sum())
    
    print(df.groupby('object_type')['confidence'].mean())
    print(df.groupby('object_type')['confidence'].var())

    print(df.describe(include=['object']))


main()