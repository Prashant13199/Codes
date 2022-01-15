import random
def func1():
    print('     ____')
    print('     |  |')
    print('     |   ')
    print('     |   ')
    print('     |   ')
    print('     |   ')
    print('     |   ')
    print(' ____|______   ')
    
def func2():
    print('     ____')
    print('     |  |')
    print('     |  0')
    print('     |   ')
    print('     |   ')
    print('     |   ')
    print('     |   ')
    print(' ____|______   ')

def func3():
    print('     ____')
    print('     |  |')
    print('     |  0')
    print('     |  |')
    print('     |   ')
    print('     |   ')
    print('     |   ')
    print(' ____|______   ')

def func4():
    print('     ____')
    print('     |  |')
    print('     |  0')
    print('     |  |')
    print('     |  |')
    print('     |   ')
    print('     |   ')
    print(' ____|______   ')
    
def func5():
    print('     ____')
    print('     |  |')
    print('     |  0')
    print('     | \|')
    print('     |  |')
    print('     |   ')
    print('     |   ')
    print(' ____|______   ')
    
def func6():
    print('     ____ ')
    print('     |  | ')
    print('     |  0 ')
    print('     | \|/')
    print('     |  | ')
    print('     |    ')
    print('     |    ')
    print(' ____|______   ')
    
def func7():
    print('     ____ ')
    print('     |  | ')
    print('     |  0 ')
    print('     | \|/')
    print('     |  | ')
    print('     |    ')
    print('     |    ')
    print(' ____|______   ')
    
def func8():
    print('     ____ ')
    print('     |  | ')
    print('     |  0 ')
    print('     | \|/')
    print('     |  | ')
    print('     | /   ')
    print('     |    ')
    print(' ____|______   ')
    

def func9():
    
    print('     ____ ')
    print('     |  |  ')
    print('     |  0  ')
    print('     | \|/ ')
    print('     |  |  ')
    print('     | / \ ')
    print('     |     ')
    print(' ____|_____')
     
lists=['tower','designed','black','ironman','elephant','hangman']

word=random.choice(lists)

orig=list(word)
ques=orig.copy()
for i in range(10):
    j=random.randint(0,len(orig)-1)
    ques[j]='_'
    
print(' '.join(ques))

chance=10
for i in range(100):
    flag=0
    l=input('Enter the letter')
    for a in range(len(orig)):
        if orig[a]==l:
            flag=1
            ques[a]=orig[a]
    if flag==0:
        print('Word not present, Try again')
        chance-=1
        if chance==9:
            func1()
        if chance==8:
            func2()
            
        elif chance==7:
            func3()
            
        elif chance==6:
            func4()
        
        elif chance==5:
           
            func5()
        elif chance==4:
            
            func6()
            
        elif chance==3:
            
            func7()
        elif chance==2:
            func8()
        elif chance==1:
            func9()
            print()
            print('You Lost..............sorry')
            break
        print(chance,' chances remaining')
        #continue
    if flag==1:
        if ('_' in ques) == False:
            print(word)
            print('Congrats You won!!!!')
            break
    
    print(' '.join(ques))
        



                     
    
        
    #print(l)