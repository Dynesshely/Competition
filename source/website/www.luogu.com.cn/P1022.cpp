#include <bits/stdc++.h>

struct section
{
    std::vector<int> prefixes;

    bool isX = false, isNagative = false;

    int getValue()
    {
        int result = 0, p = 0;

        if (prefixes.size() == 0 && isX) return 1;

        for (int i = prefixes.size() - 1; i >= 0; -- i)
        {
            result += prefixes[i] * pow(10, p);
            ++ p;
        }

        return isNagative ? -result : result;
    }
};

int main(){
    
    std::vector<section> left, right, *cs = &left; // cs -> current sections

    std::string equation;

    std::cin >> equation;

    section current;

    char unknown = 'x';

    bool skipFirstNegative = true;

    for (int i = 0; i < equation.length(); ++ i)
    {
        if (equation[i] == '+')
        {
            skipFirstNegative = false;
            cs->push_back(current);
            current = section();
            continue;
        }

        if (equation[i] == '-')
        {
            if (cs->size() != 0 || skipFirstNegative == false)
            {
                cs->push_back(current);
                current = section();
            }
            current.isNagative = true;
            continue;
        }

        if (equation[i] == '=')
        {
            cs->push_back(current);
            current = section();
            cs = &right;
            continue;
        }

        if (equation[i] >= '0' && equation[i] <= '9')
        {
            skipFirstNegative = false;
            current.prefixes.push_back(equation[i] - '0');
            continue;
        }

        current.isX = true;

        unknown = equation[i];
    }

    cs->push_back(current);

    // debug

    // for (int i = 0; i < left.size(); ++ i)
    // {
    //     std::cout << i << ": " << left[i].isX << " " << left[i].isNagative << " " << left[i].getValue() << std::endl;
    // }

    // for (int i = 0; i < right.size(); ++ i)
    // {
    //     std::cout << i << ": " << right[i].isX << " " << right[i].isNagative << " " << right[i].getValue() << std::endl;
    // }

    int leftSum = 0, rightSum = 0, leftXSum = 0, rightXSum = 0;

    for (int i = 0; i < left.size(); ++ i)
    {
        if (left[i].isX)
            leftXSum += left[i].getValue();
        else
            leftSum += left[i].getValue();
    }

    for (int i = 0; i < right.size(); ++ i)
    {
        if (right[i].isX)
            rightXSum += right[i].getValue();
        else
            rightSum += right[i].getValue();
    }

    int xSum = leftXSum - rightXSum, sum = rightSum - leftSum;
    
    double result = (sum * 1.0) / (xSum * 1.0);

    if (sum == 0) result = 0;

    printf("%c=%.3f\n", unknown, result);

    return 0;
}

