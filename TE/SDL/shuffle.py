#!/usr/bin/env python
# coding: utf-8

# In[66]:



import random
f = open("original.txt","r")
f2= open("shuffle_original.txt","w")

#create the file in home directory
#print(f.read())

word_shuffle_count=0

for line in f:
    words=line.split()
    the_sentence=''
    
    for single_word in words:
        new_shuffled_word=''        
        if( len(single_word) >3):
            #check if the word ends with a special 
            specials="!?.,(){}[]`/"
            for symbol in specials:
                if single_word[-1]==symbol:
                    only_the_word=single_word[0:-1]
                    #if it does end with a special symbol, don't consider it as the part of the word
                    end_char=symbol
            else:
                only_the_word=single_word[:] 
                end_char=''
            #do the shuffle
            shuffling_part=only_the_word[1:-1]
            #shuffling is to be done on the complete string but leaving first and last letter as it is 
            shuffled_part=random.sample(shuffling_part,len(shuffling_part))            
            #above gives a list of shuffled characters in a string          
            
            shuffled_word_part=''.join(shuffled_part)
            #converted shuffled_part into string
            new_shuffled_word=''.join(only_the_word[0]+shuffled_word_part+only_the_word[-1]+end_char)
            #join all the parts of the string
            the_sentence=the_sentence+new_shuffled_word+" "
            #append all the jumbled words in the line 
            #add a white-space at the end of each word
            
            word_shuffle_count+=1
        else:            
            new_shuffled_word=single_word
            the_sentence=the_sentence+single_word+" "
            
    print(the_sentence,end='') 
    f2.write(the_sentence)
    f2.write("\n")
    print("\n")
    
print(word_shuffle_count)


# In[ ]:





# In[ ]:




