#include <algorithm>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

int getval(int size)
{
    if (size < 15)
        return size;
    else
        return 15;
}

class Puntos
{
public:
    int x, y;
    aleatoriox();
    aleatorioy();
};

int Puntos::aleatoriox() {

    return x = rand();
}

int Puntos::aleatorioy() {

    return y = rand();
}

bool compare_x(Puntos& a, Puntos& b)
{
    if (a.x < b.x)
        return true;
    else
        return false;
}
bool compare_y(Puntos& a, Puntos& b)
{
    if (a.y < b.y)
        return true;
    else
        return false;
}

//calculates distance between a pair of points
double calc_distance(punto_par pair)
{
    int k1 = abs(pair.a.x - pair.b.x);
    int k2 = abs(pair.a.y - pair.b.y);
    size_t k3 = k1 * k1;
    size_t k4 = k2 * k2;
    size_t k5 = k3 + k4;
    return sqrt(k5);
}

punto_par minimal_distance_naive(vector<Puntos> points)
{
    punto_par min;
    min.a = points[0];
    min.b = points[1];

    for (int i = 0; i < points.size(); i++)
    {
        punto_par temp;
        temp.a = points[i];

        for (int j = i + 1; j < points.size(); j++)
        {
            temp.b = points[j];

            if (calc_distance(temp) < calc_distance(min))
            {
                min = temp;
            }
        }
    }
    return min;
}

punto_par minimal_distance_rec(vector<Puntos> points_x, vector<Puntos> points_y)
{

    if (points_x.size() <= 3)
    {
        return minimal_distance_naive(points_x);
    }

    else
    {
        int mid = points_x.size() / 2;
        vector<Puntos> left_x, left_y;
        vector<Puntos> right_x, right_y;

        for (int i = 0; i < mid; i++)
        {
            left_x.push_back(points_x[i]);
        }
        for (int i = mid; i < points_x.size(); i++)
        {
            right_x.push_back(points_x[i]);
        }

        int middle = points_x[mid - 1].x;

        for (int i = 0; i < points_y.size(); i++)
        {
            if (points_y[i].x <= middle)
            {
                left_y.push_back(points_y[i]);
            }
            else
            {
                right_y.push_back(points_y[i]);
            }
        }

        punto_par left = minimal_distance_rec(left_x, left_y);
        punto_par right = minimal_distance_rec(right_x, right_y);

        double d_left = calc_distance(left);
        double d_right = calc_distance(right);
        punto_par min;
        double min_distance;
        if (d_left <= d_right)
        {
            min_distance = d_left;
            min = left;
        }
        else
        {
            min_distance = d_right;
            min = right;
        }
        vector<Puntos> middle_set;
        for (int i = 0; i < points_y.size(); i++)
        {
            if (abs(points_y[i].x - middle) <= min_distance)
            {
                middle_set.push_back(points_y[i]);
            }
        }

        if (middle_set.size() < 2)
        {
            return min;
        }

        punto_par init;
        init.a = middle_set[0];
        init.b = middle_set[1];
        double k = 0, m = calc_distance(init);
        punto_par tmp, min_tmp = init;

        for (int i = 0; i < middle_set.size(); i++)
        {
            tmp.a = middle_set[i];
            for (int j = i + 1; j <= getval(middle_set.size() - 1); j++)
            {
                tmp.b = middle_set[j];
                k = calc_distance(tmp);
                if (k < m)
                {
                    m = k;
                    min_tmp = tmp;
                }
            }
        }
        if (min_distance < m)
            return min;
        else
            return min_tmp;
    }
}

double minimal_distance(vector<int> x, vector<int> y)
{
    vector<Puntos> points(x.size());
    for (int i = 0; i < x.size(); i++)
    {
        points[i].x = x[i];
        points[i].y = y[i];
    }

    sort(points.begin(), points.end(), compare_x);
    vector<Puntos> points_x = points;

    sort(points.begin(), points.end(), compare_y);
    vector<Puntos> points_y = points;

    punto_par p = minimal_distance_rec(points_x, points_y);
    return calc_distance(p);
}

int main()
{
    size_t n;
    std::cin >> n;
    vector<int> x(n);
    vector<int> y(n);
    for (size_t i = 0; i < n; i++)
    {
        cin >> x[i] >> y[i];
    }
    cout << fixed;
    cout << setprecision(9) << minimal_distance(x, y) << "\n";
}
