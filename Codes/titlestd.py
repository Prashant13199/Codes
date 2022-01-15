import pandas as pd
import numpy as np
import re

df = pd.read_excel(r'judges_compiled_data.xlsx')
#print(df)

pattern1 = re.compile(r'judge|Judge')
pattern2 = re.compile(r'Justice|justice')

no_obj=int(df['Title'].count())
#print(no_obj)

i=0
while i<no_obj:
    if(pattern2.search(str(df['Title'][i]))!=None):
        df['Title'][i]='Chief Justice'
    #print(pattern1.search(str(df['Title'][i]))!=None)
    if(pattern1.search(str(df['Title'][i])))!=None:
        df['Title'][i]='Judge'
        #continue
    i+=1

df.to_csv(r'new12.csv', index=False)

