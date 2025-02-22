#include <iostream>
#include <vector>

using namespace std;

class CenterLineInterpolator
{
private:
    vector<pair<double, double>> midPoints;

public:
    void addMidPoint(double x, double y)
    {
        midPoints.emplace_back(x, y);
    }

    vector<double> interpolateY(double x)
    {
        vector<double> yValues;
        size_t n = midPoints.size();
        if (n < 2) return yValues;

        for (int i = 0; i < n; i++)
        {
            int j = (i + 1) % n;

            double x1 = midPoints[i].first, y1 = midPoints[i].second;
            double x2 = midPoints[j].first, y2 = midPoints[j].second;


            if ((x1 <= x && x <= x2) || (x2 <= x && x <= x1))
            {
                double t = (x - x1) / (x2 - x1);
                double y = y1 + t * (y2 - y1);
                yValues.emplace_back(y);
            }
        }
        return yValues;
    }
};

