The bug was that the determinants weren't being computed properly.
In both overloadmatrix and psmatrix, the determinants weren't actually summing the values.
I fixed the bug by making the determinants sum to correctly compute the values.
Note: the interger matrix did not have the bug

//FROM OVERLOADMATRIX: val wasn't summing, so I changed it to val+= 
template<class T, int h, int w>
T
determinant(const Matrix<T, h, w> &m)
{
    T val = 0;
    for(int i = 0; i < h; i++) {
        val += (i % 2 ? -1 : 1) * m(i, 0) * m.minor(i, 0).determinant(); //this line wasn't summing
    }
    return val;
}

FROM PSMATRIX: val wasn't summing, changed to val+=
    T determinant() const {
        T val = 0;
        for(int i = 0; i < h; i++) {
            val += (i % 2 ? -1 : 1)         //wasn't summing
                   * data[i][0]
                   * minor(i, 0).determinant();
        }
        return val;
    }