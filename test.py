import pandas as pd
df=pd.read_csv("4708263_L2WVCILL.csv")
# for ind, i in enumerate(df.timestamp):
#     if i<date:
#     df["profit"]= df["price"]*df["trade"]
#     df1=df[df["timestamp"]<date]
#     prod=sum(df1["profit"])
#     sum1=sum(df1["trade"])
#     prod += (sum1*(-1))*df1["price"].iloc[len(df1)-1]