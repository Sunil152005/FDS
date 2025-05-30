#include <iostream>
using namespace std;

int add(int S1[100][3], int S2[100][3], int R[100][3])
 {
    int i = 1, j = 1, c = 1;
    R[0][0] = S1[0][0];
    R[0][1] = S1[0][1];
    R[0][2] = 0;
    while (i <= S1[0][2] && j <= S2[0][2])
        {
        if (S1[i][0] < S2[j][0])
        {
            R[c][0] = S1[i][0];
            R[c][1] = S1[i][1];
            R[c][2] = S1[i][2];
            i++;
        } else if (S1[i][0] > S2[j][0])
        {
            R[c][0] = S2[j][0];
            R[c][1] = S2[j][1];
            R[c][2] = S2[j][2];
            j++;
        } else
        {
            if (S1[i][1] < S2[j][1])
            {
                R[c][0] = S1[i][0];
                R[c][1] = S1[i][1];
                R[c][2] = S1[i][2];
                i++;
            } else if (S1[i][1] > S2[j][1])
            {
                R[c][0] = S2[j][0];
                R[c][1] = S2[j][1];
                R[c][2] = S2[j][2];
                j++;
            } else
            {
                R[c][0] = S1[i][0];
                R[c][1] = S1[i][1];
                R[c][2] = S1[i][2] + S2[j][2];
                i++;
                j++;
            }
        }
        c++;
        }

    while (i <= S1[0][2])
    {
        R[c][0] = S1[i][0];
        R[c][1] = S1[i][1];
        R[c][2] = S1[i][2];
        i++;
        c++;
    }

    while (j <= S2[0][2])
    {
        R[c][0] = S2[j][0];
        R[c][1] = S2[j][1];
        R[c][2] = S2[j][2];
        j++;
        c++;
    }

    R[0][2] = c - 1;
    return c;
}

void sparse(int M[100][100], int m, int n, int S[100][3])
{
    int k = 1;
    S[0][0] = m;
    S[0][1] = n;
    S[0][2] = 0;

    for (int i = 0; i < m; i++)
        {
        for (int j = 0; j < n; j++)
        {
            if (M[i][j] != 0)
            {
                S[k][0] = i;
                S[k][1] = j;
                S[k][2] = M[i][j];
                k++;
            }
        }
    }
    S[0][2] = k - 1;
}

void transpose(int S[20][3],int R[20][3])
{
    int i,j;
    int C=1;
    R[0][0]=S[0][1];
    R[0][1]=S[0][0];
    R[0][2]=S[0][2];
    for(i=0;i<S[0][1];i++)
    {
        for(j=0;j<=S[0][2];j++)
        {
            if (S[j][1]==i)
            {
                R[C][0]=S[j][1];
                R[C][1]=S[j][0];
                R[C][2]=S[j][2];
                C++;
            }
        }
    }
}

void display(int S[100][3])
{
    for (int i = 0; i <= S[0][2]; i++)
        {
        cout << S[i][0] << "\t" << S[i][1] << "\t" << S[i][2] << endl;
        }
}

int main()
{
    int M1[100][100], m, n;
    int M2[100][100], p, q;
    int S1[100][3], S2[100][3], R[100][3];

    int cn1 = 0, cn2 = 0;

    cout << "Enter the number of rows and columns of the first matrix: ";
    cin >> m >> n;
    cout << "Enter the elements of the first matrix:\n";
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> M1[i][j];
            if (M1[i][j] != 0) cn1++;
        }
    }

    cout << "Enter the number of rows and columns of the second matrix: ";
    cin >> p >> q;
    cout << "Enter the elements of the second matrix:\n";
    for (int i = 0; i < p; i++)
    {
        for (int j = 0; j < q; j++)
        {
            cin >> M2[i][j];
            if (M2[i][j] != 0) cn2++;
        }
    }

    int ch = 9;
    while (ch != 0)
    {
        cout << "\nMenu\n";
        cout << "1. Sparse Matrix\n";
        cout << "2. Add Sparse Matrix\n";
        cout << "3. Transpose Matrix\n";
        cout << "Enter the Choice: ";
        cin >> ch;

        switch (ch)
        {
        case 1:
            if (cn1 < (m * n) / 2)
            {
                sparse(M1, m, n, S1);
                cout << "Sparse of the first matrix:" << endl;
                display(S1);
            } else
            {
                cout << "First matrix cannot be sparse!" << endl;
            }

            if (cn2 < (p * q) / 2)
            {
                sparse(M2, p, q, S2);
                cout << "Sparse of the second matrix:" << endl;
                display(S2);
            } else
            {
                cout << "Second matrix cannot be sparse!" << endl;
            }
            break;

        case 2:
            if (m == p && n == q)
            {
                add(S1, S2, R);
                cout << "Sparse Matrix after addition:" << endl;
                display(R);
            } else
            {
                cout << "Matrices dimensions do not match for addition!" << endl;
            }
            break;

        case 3:
            cout << "Transpose of the first matrix:" << endl;
            transpose(S1,R);
            display(R);

            cout << "Transpose of the second matrix:" << endl;
            transpose(S2,R);
            display(R);

            break;

        default:
            cout << "Invalid choice" << endl;
        }
    }
    return 0;
}

