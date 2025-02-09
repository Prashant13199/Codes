# Union of Two Fuzzy Sets
A = dict()
B = dict()
Y = dict()
  
A = {"a": 0.2, "b": 0.3, "c": 0.6, "d": 0.6}
B = {"a": 0.9, "b": 0.9, "c": 0.4, "d": 0.5}
  
print('The First Fuzzy Set is :', A)
print('The Second Fuzzy Set is :', B)
  
  
for A_key, B_key in zip(A, B):
    A_value = A[A_key]
    B_value = B[B_key]
  
    if A_value > B_value:
        Y[A_key] = A_value
    else:
        Y[B_key] = B_value
          
print('Fuzzy Set Union is :', Y)

# OUTPUT :
# The First Fuzzy Set is : {'a': 0.2, 'b': 0.3, 'c': 0.6, 'd': 0.6}
# The Second Fuzzy Set is : {'a': 0.9, 'b': 0.9, 'c': 0.4, 'd': 0.5}
# Fuzzy Set Union is : {'a': 0.9, 'b': 0.9, 'c': 0.6, 'd': 0.6}

# Intersection of Two Fuzzy Sets
A = dict()
B = dict()
Y = dict()
  
A = {"a": 0.2, "b": 0.3, "c": 0.6, "d": 0.6}
B = {"a": 0.9, "b": 0.9, "c": 0.4, "d": 0.5}
  
print('The First Fuzzy Set is :', A)
print('The Second Fuzzy Set is :', B)
  
  
for A_key, B_key in zip(A, B):
    A_value = A[A_key]
    B_value = B[B_key]
  
    if A_value < B_value:
        Y[A_key] = A_value
    else:
        Y[B_key] = B_value
print('Fuzzy Set Intersection is :', Y)

# OUTPUT :
# The First Fuzzy Set is : {'a': 0.2, 'b': 0.3, 'c': 0.6, 'd': 0.6}
# The Second Fuzzy Set is : {'a': 0.9, 'b': 0.9, 'c': 0.4, 'd': 0.5}
# Fuzzy Set Intersection is : {'a': 0.2, 'b': 0.3, 'c': 0.4, 'd': 0.5}

# Difference Between Two Fuzzy Sets
A = dict()
Y = dict()
  
A = {"a": 0.2, "b": 0.3, "c": 0.6, "d": 0.6}
  
print('The Fuzzy Set is :', A)
  
  
for A_key in A:
   Y[A_key]= 1-A[A_key]
          
print('Fuzzy Set Complement is :', Y)

# OUTPUT :
# The Fuzzy Set is : {'a': 0.2, 'b': 0.3, 'c': 0.6, 'd': 0.6}
# Fuzzy Set Complement is : {'a': 0.8, 'b': 0.7, 'c': 0.4, 'd': 0.4}



# Difference Between Two Fuzzy Sets
A = dict()
B = dict()
Y = dict()
  
A = {"a": 0.2, "b": 0.3, "c": 0.6, "d": 0.6}
B = {"a": 0.9, "b": 0.9, "c": 0.4, "d": 0.5}
  
print('The First Fuzzy Set is :', A)
print('The Second Fuzzy Set is :', B)
  
  
for A_key, B_key in zip(A, B):
    A_value = A[A_key]
    B_value = B[B_key]
    B_value = 1 - B_value
  
    if A_value < B_value:
        Y[A_key] = A_value
    else:
        Y[B_key] = B_value
          
print('Fuzzy Set Difference is :', Y)

# OUTPUT :
# The First Fuzzy Set is : {"a": 0.2, "b": 0.3, "c": 0.6, "d": 0.6}
# The Second Fuzzy Set is : {"a": 0.9, "b": 0.9, "c": 0.4, "d": 0.5}
# Fuzzy Set Difference is : {"a": 0.1, "b": 0.1, "c": 0.6, "d": 0.5}




