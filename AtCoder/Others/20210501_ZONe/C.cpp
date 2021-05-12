#include <iostream>
#include <algorithm>

using namespace std;

struct person
{
    long long int A;
    long long int B;
    long long int C;
    long long int D;
    long long int E;
};

long long int CalStatus(person p0, person p1, person p2)
{
    long long int Status;
    long long int maxA, maxB, maxC, maxD, maxE;

    maxA = max({p1.A, p2.A, p0.A});
    maxB = max({p1.B, p2.B, p0.B});
    maxC = max({p1.C, p2.C, p0.C});
    maxD = max({p1.D, p2.D, p0.D});
    maxE = max({p1.E, p2.E, p0.E});

    Status = min({maxA, maxB, maxC, maxD, maxE});

    return Status;
}



int main()
{
    int N;
    cin >> N;

    person p3, p[3];

    //とりあえず3人分入力, p3は新規メンバ
    for (int i = 0; i < 3; i++)
    {
        cin >> p[i].A >> p[i].B >> p[i].C >> p[i].D >> p[i].E;
    }

    long long int Status;

    //答え
    Status = CalStatus(p[0], p[1], p[2]);

    //tmp
    long long int Status0, Status1, Status2, tmp_max;

    for (int i = 4; i <= N; i++)
    {
        cin >> p3.A >> p3.B >> p3.C >> p3.D >> p3.E;
        Status0 = CalStatus(p3, p[1], p[2]);
        Status1 = CalStatus(p[0], p3, p[2]);
        Status2 = CalStatus(p[0], p[1], p3);
        tmp_max = max({Status0, Status1, Status2});
        if (tmp_max > Status)
        {
            Status = tmp_max;
            if (Status0 >= Status1 && Status0 >= Status2)
            {
                p[0] = p3;
                continue;
            }
            else if (Status1 >= Status0 && Status1 >= Status2)
            {
                p[1] = p3;
                continue;
            }
            else if (Status2 >= Status0 && Status2 >= Status1)
            {
                p[2] = p3;
                continue;
            }
        }
        else
        {
        }
    }

    cout << Status << endl;

    return 0;
}