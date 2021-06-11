#include <stdio.h>
#include <stdlib.h>

int main()
{
    int **a; // ������� ������
    int *d;  // ����������� ����������
    int *v;  // ���������� �������
    int temp;
    int minindex, min;
    int i, j;
    int N;
    printf ("Number of vertex:");
    scanf ("%d", &N);
    a = (int **)malloc(N * sizeof(int*));
    d = (int*)malloc(N * sizeof(int));
    v =(int*)malloc(N * sizeof(int));
    for (i = 0; i < N; i ++)
        a[i] = (int *)malloc(N * sizeof(int));
    // ������������� ������� ������
    for (i = 0; i<N; i++)
    {
        a[i][i] = 0;
        for (j = i + 1; j<N; j++) {
            printf("Distance between %d - %d: ", i + 1, j + 1);
            scanf("%d", &temp);
            a[i][j] = temp;
            a[j][i] = temp;
        }
    }
    // ����� ������� ������
    for (i = 0; i<N; i++)
    {
        for (j = 0; j<N; j++)
            printf("%5d ", a[i][j]);
        printf("\n");
    }
    //������������� ������ � ����������
    for (i = 0; i<N; i++)
    {
        d[i] = 1000;
        v[i] = 1;
    }
    d[0] = 0;
    // ��� ���������
    do
    {
        minindex = 1000;
        min = 1000;
        for (i = 0; i<N; i++)
        {     // ���� ������� ��� �� ������ � ��� ������ min
            if ((v[i] == 1) && (d[i]<min))
            { // ��������������� ��������
                min = d[i];
                minindex = i;
            }
        }
    // ��������� ��������� ����������� ���
    // � �������� ���� �������
    // � ���������� � ������� ����������� ����� �������
        if (minindex != 1000)
        {
            for (i = 0; i<N; i++)
            {
                if (a[minindex][i] > 0)
                {
                    temp = min + a[minindex][i];
                    if (temp < d[i])
                        d[i] = temp;
                }
            }
            v[minindex] = 0;
        }
    }
    while (minindex < 1000);
  // ����� ���������� ���������� �� ������
    printf("\nShortest distances to vertices: \n");
    for (i = 0; i<N; i++)
        printf("%5d ", d[i]);

  // �������������� ����
    int *ver; // ������ ���������� ������
    ver = (int*)malloc(N * sizeof(int));
    int end = N - 1;  // ������ �������� ������� = N - 1
    ver[0] = end + 1; // ��������� ������� - �������� �������
    for (i = 1; i < N; i ++)
        ver[i] = 0;
    int k = 1; // ������ ���������� �������
    int weight = d[end]; // ��� �������� �������

    while (end > 0) // ���� �� ����� �� ��������� �������
    {
        for(i=0; i<N; i++) // ������������� ��� �������
        if (a[end][i] != 0)   // ���� ����� ����
        {
            int temp = weight - a[end][i]; // ���������� ��� ���� �� ���������� �������
            if (temp == d[i])   // ���� ��� ������ � ������������
            {                   // ������ �� ���� ������� � ��� �������
                weight = temp;  // ��������� ����� ���
                end = i;        // ��������� ���������� �������
                ver[k] = i + 1; // � ���������� �� � ������
                k++;
            }
        }
    }
    // ����� ���� (��������� ������� ��������� � ����� ������� �� k ���������)
    printf("\nFinding the shortest path\n");
    for (i = k-1; i>=0; i--)
        printf("%3d ", ver[i]);
    getchar();
    getchar();
  return 0;
}
