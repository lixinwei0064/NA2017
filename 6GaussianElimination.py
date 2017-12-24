def principle(a, t):
    '''
    This function finds the principle element of column t of matrix a
    and returns the row num

    :param prin: this is the largest element so far in the column
    :param num: this is the row number of prin
    '''
    prin = 0.
    num = t
    for i in range(t, 9):
        if abs(a[i][t]) > prin:
            prin = abs(a[i][t])
            num = i
    return num
def elimination(a, b):
    '''
    This function eliminates the augmented matrix and returns the result

    :param prin: gets the pivot from the function 'principle'
    '''
    for i in range(8):
        prin = principle(a, i)
        a[i], a[prin] = a[prin], a[i]
        b[i], b[prin] = b[prin], b[i]
        for j in range(i+1, 9):
            fac = -a[j][i]/a[i][i]
            a[j][i] = 0
            for k in range(i+1, 9):
                a[j][k] += fac*a[i][k]
            b[j] += fac*b[i]
    return a, b
def solve(a, b):
    '''
    This function solves the lower triangular matrix and returns the solution
    '''
    x = []
    for i in range(8, -1, -1):
        ans = b[i]
        for j in range(8, i, -1):
            ans -= a[i][j]*x[j-9]
        ans /= a[i][i]
        x = [ans]+x
    return x
a = [[31., -13., 0., 0., 0., -10., 0., 0., 0., 0.],\
     [-13.,35.,-9.,0.,-11.,0.,0.,0.,0.],\
     [0.,-9.,31.,-10.,0.,0.,0.,0.,0.],\
     [0.,0.,-10.,79.,-30.,0.,0.,0.,-9.],\
     [0.,0.,0.,-30.,57.,-7.,0.,-5.,0.],\
     [0.,0.,0.,0.,-7.,47.,-30.,0.,0.],\
     [0.,0.,0.,0.,0.,-30.,41.,0.,0.],\
     [0.,0.,0.,0.,-5.,0.,0.,27.,-2.],\
     [0.,0.,0.,-9.,0.,0.,0.,-2.,29.]]
b = [-15.,27.,-23.,0.,-20.,12.,-7.,7.,10]
ae,be = elimination(a,b)
x = solve(ae,be)
print x
'''
Output
[-0.28923381601575443, 0.34543571577911547, -0.7128117310868789, -0.22060851057052858, -0.43040043270402234, 0.15430873983831117, -0.05782287328904062, 0.2010538948236807, 0.29022866187974494]
'''