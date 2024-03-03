/* Notice that there might occur some problem with the file path */

#include<iostream>
#include<fstream>
#define ST_NUM 10  /* The number of students */
#define SC_NUM 3  /* The number of courses  */
using namespace std;
int main()
{
    ifstream ifs;
    ifs.open("stuInfo.txt");
    int i, j, tmp;
    string buf;
    string s_name [ST_NUM];           /* Array of student names */
    int    score_t[ST_NUM][SC_NUM];   /* Table of every entry  */
    int    max    [SC_NUM];           /* Maximum scores */
    int    min    [SC_NUM];           /* Minimum scores */
    float  sc_avg [SC_NUM] = {0};     /* Average scores of a student */
    float  st_avg [ST_NUM] = {0};     /* Average scores of a course */
    if(!ifs)
    {
        cerr << "File doesn't exist or it's occupied" << endl;
    }
    for(i = 0; i < ST_NUM; i++)
    {
        ifs >> s_name[i];             /* Read ith student's name */
        for(j = 0; j < SC_NUM; j++)
        {
            ifs >> tmp;               /* Read jth score of ith student */
            score_t[i][j] = tmp; 
            st_avg [i]    += (float) tmp;   
            sc_avg [j]    += (float) tmp;
            if(i == 0 || tmp > max[j])
                max[j] = tmp;
            if(i == 0 || tmp < min[j])
                min[j] = tmp;
        }
    }
    ifs.close();
    cout << "no\tname\tscore1\tscore2\tscore3\taverage" << endl;  /* Print the table */
    for(i = 0; i < ST_NUM; i++)
    {
        cout << i + 1 << "\t" << s_name[i] << "\t";               /* Print the name of ith student */
        for(j = 0; j < SC_NUM; j++)
        {
            cout << score_t[i][j] << "\t";                        /* Print the jth score of ith student*/
        }
        cout << st_avg[i] / SC_NUM << endl;                       /* Print the average score of ith student */
    }
    cout << "\taverage\t";
    for(j = 0; j < SC_NUM; j++)
    {
        cout << sc_avg[j] / ST_NUM << "\t";                       /* Print the average score of jth course */
    }
    cout << endl << "\tmin\t";
    for(j = 0; j < SC_NUM; j++)
    {
        cout << min[j] << "\t";                                   /* Print the minimum score of jth course */
    }
    cout << endl << "\tmax\t";
    for(j = 0; j < SC_NUM; j++)
    {
        cout << max[j] << "\t";                                   /* Print the maximum score of jth course */
    }
}