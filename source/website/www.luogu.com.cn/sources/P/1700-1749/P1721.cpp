#include <bits/stdc++.h>

using namespace std;

template<const int modVal> struct modInt {
    int valX;
    constexpr modInt(int initX = 0)
        : valX(initX) {}
    constexpr inline modInt  operator+() const { return *this; }
    constexpr inline modInt  operator-() const { return !valX ? 0 : modVal - valX; }
    constexpr inline modInt &operator++() {
        ++valX;
        if (valX >= modVal)
            valX -= modVal;
        return *this;
    }
    constexpr inline modInt &operator--() {
        --valX;
        if (valX < 0)
            valX += modVal;
        return *this;
    }
    constexpr inline modInt operator++(int) {
        int resVal = valX;
        if (valX >= modVal)
            valX -= modVal;
        return resVal;
    }
    constexpr inline modInt operator--(int) {
        int resVal = valX;
        if (valX < 0)
            valX += modVal;
        return resVal;
    }
    constexpr inline modInt operator+(const modInt &rhs) const {
        int resVal = valX;
        resVal += rhs.valX;
        if (resVal >= modVal)
            resVal -= modVal;
        return resVal;
    }
    constexpr inline modInt operator-(const modInt &rhs) const {
        int resVal = valX;
        resVal -= rhs.valX;
        if (resVal < 0)
            resVal += modVal;
        return resVal;
    }
    constexpr inline modInt  operator*(const modInt &rhs) const { return (int)((long long)valX * rhs.valX % modVal); }
    constexpr inline modInt &operator+=(const modInt &rhs) {
        valX += rhs.valX;
        if (valX >= modVal)
            valX -= modVal;
        return *this;
    }
    constexpr inline modInt &operator-=(const modInt &rhs) {
        valX -= rhs.valX;
        if (valX < 0)
            valX += modVal;
        return *this;
    }
    constexpr inline modInt &operator*=(const modInt &rhs) {
        valX = (int)((long long)valX * rhs.valX % modVal);
        return *this;
    }
    template<typename typeG> constexpr inline modInt operator^(typeG rhs) const {
        modInt baseVal = valX, resVal = 1;
        while (rhs) {
            if (rhs & 1)
                resVal *= baseVal;
            baseVal *= baseVal;
            rhs >>= 1;
        }
        return resVal;
    }
    constexpr inline modInt  calcInv() const { return *this ^ (modVal - 2); }
    constexpr inline modInt  operator/(const modInt &rhs) const { return (*this) * rhs.calcInv(); }
    constexpr inline modInt &operator/=(const modInt &rhs) { return (*this) *= rhs.calcInv(); }
    constexpr inline bool    operator==(const modInt &rhs) const { return valX == rhs.valX; }
    constexpr inline bool    operator!=(const modInt &rhs) const { return valX != rhs.valX; }
    constexpr inline int    &getData() { return valX; }
};

namespace bigNum {
constexpr int prec = 6000;

class decimal {
  public:
    decimal();
    decimal(const string &str);
    decimal(const char *str);
    decimal(int valX);
    decimal(long long valX);
    decimal(double valX);

    bool isZero() const;

    string toString(int pVal) const;
    double toDouble() const;

    friend decimal operator+(const decimal &lhs, const decimal &rhs);
    friend decimal operator+(const decimal &lhs, int rhs);
    friend decimal operator+(int lhs, const decimal &rhs);
    friend decimal operator+(const decimal &lhs, long long rhs);
    friend decimal operator+(long long lhs, const decimal &rhs);
    friend decimal operator+(const decimal &lhs, double rhs);
    friend decimal operator+(double lhs, const decimal &rhs);

    friend decimal operator-(const decimal &lhs, const decimal &rhs);
    friend decimal operator-(const decimal &lhs, int rhs);
    friend decimal operator-(int lhs, const decimal &rhs);
    friend decimal operator-(const decimal &lhs, long long rhs);
    friend decimal operator-(long long lhs, const decimal &rhs);
    friend decimal operator-(const decimal &lhs, double rhs);
    friend decimal operator-(double lhs, const decimal &rhs);

    friend decimal operator*(const decimal &lhs, int rhs);
    friend decimal operator*(int lhs, const decimal &rhs);

    friend decimal operator/(const decimal &lhs, int rhs);

    friend bool operator<(const decimal &lhs, const decimal &rhs);
    friend bool operator>(const decimal &lhs, const decimal &rhs);
    friend bool operator<=(const decimal &lhs, const decimal &rhs);
    friend bool operator>=(const decimal &lhs, const decimal &rhs);
    friend bool operator==(const decimal &lhs, const decimal &rhs);
    friend bool operator!=(const decimal &lhs, const decimal &rhs);

    decimal &operator+=(int rhs);
    decimal &operator+=(long long rhs);
    decimal &operator+=(double rhs);
    decimal &operator+=(const decimal &rhs);

    decimal &operator-=(int rhs);
    decimal &operator-=(long long rhs);
    decimal &operator-=(double rhs);
    decimal &operator-=(const decimal &rhs);

    decimal &operator*=(int rhs);

    decimal &operator/=(int rhs);

    friend decimal operator-(const decimal &val);

    friend decimal operator*(const decimal &lhs, double rhs);
    friend decimal operator*(double lhs, const decimal &rhs);
    friend decimal operator/(const decimal &lhs, double rhs);
    decimal       &operator*=(double rhs);
    decimal       &operator/=(double rhs);

  private:
    static const int len = prec / 9 + 1;
    static const int mo  = 1000000000;

    static void appendToString(string &str, long long valX);

    bool      isNeg;
    long long integerVal;
    int       dataArr[len];

    void initZero();
    void initFromStr(const char *str);
};

decimal::decimal() { this->initZero(); }

decimal::decimal(const char *str) { this->initFromStr(str); }

decimal::decimal(const string &str) { this->initFromStr(str.c_str()); }

decimal::decimal(int valX) {
    this->initZero();

    if (valX < 0) {
        isNeg = true;
        valX  = -valX;
    }

    integerVal = valX;
}

decimal::decimal(long long valX) {
    this->initZero();

    if (valX < 0) {
        isNeg = true;
        valX  = -valX;
    }

    integerVal = valX;
}

decimal::decimal(double valX) {
    this->initZero();

    if (valX < 0) {
        isNeg = true;
        valX  = -valX;
    }

    integerVal = (long long)valX;
    valX -= integerVal;

    for (int i = 0; i < len; i++) {
        valX *= mo;
        if (valX < 0)
            valX = 0;
        dataArr[i] = (int)valX;
        valX -= dataArr[i];
    }
}

void decimal::initZero() {
    isNeg      = false;
    integerVal = 0;
    memset(dataArr, 0, len * sizeof(int));
}

bool decimal::isZero() const {
    if (integerVal)
        return false;
    for (int i = 0; i < len; i++) {
        if (dataArr[i])
            return false;
    }
    return true;
}

void decimal::initFromStr(const char *str) {
    this->initZero();

    isNeg      = false;
    integerVal = 0;

    while (*str != 0) {
        if (*str == '-') {
            isNeg = true;
            ++str;
            break;
        } else if (*str >= 48 && *str <= 57) {
            break;
        }
        ++str;
    }

    while (*str >= 48 && *str <= 57) {
        integerVal = integerVal * 10 + *str - 48;
        ++str;
    }

    if (*str == '.') {
        int posVal = 0;
        int xVal   = mo / 10;

        ++str;
        while (posVal < len && *str >= 48 && *str <= 57) {
            dataArr[posVal] += (*str - 48) * xVal;
            ++str;
            xVal /= 10;
            if (xVal == 0) {
                ++posVal;
                xVal = mo / 10;
            }
        }
    }
}

void decimal::appendToString(string &str, long long valX) {
    if (valX == 0) {
        str.append(1, 48);
        return;
    }

    char tempArr[30];
    int  cntVal = 0;
    while (valX) {
        tempArr[cntVal++] = valX % 10;
        valX /= 10;
    }
    while (cntVal--) {
        str.append(1, tempArr[cntVal] + 48);
    }
}

string decimal::toString(int pVal) const {
    string retStr;

    if (isNeg && !this->isZero()) {
        retStr = "-";
    }

    appendToString(retStr, this->integerVal);

    retStr.append(1, '.');

    for (int i = 0; i < len; i++) {
        int xVal   = mo / 10;
        int tmpVal = dataArr[i];
        while (xVal) {
            retStr.append(1, 48 + tmpVal / xVal);
            tmpVal %= xVal;
            xVal /= 10;
            if (--pVal == 0) {
                break;
            }
        }
        if (pVal == 0)
            break;
    }

    if (pVal > 0) {
        retStr.append(pVal, '0');
    }

    return retStr;
}

double decimal::toDouble() const {
    double retVal = integerVal;

    double kVal = 1.0;
    for (int i = 0; i < len; i++) {
        kVal /= mo;
        retVal += kVal * dataArr[i];
    }

    if (isNeg) {
        retVal = -retVal;
    }

    return retVal;
}

bool operator<(const decimal &lhs, const decimal &rhs) {
    if (lhs.isNeg != rhs.isNeg) {
        return lhs.isNeg && (!lhs.isZero() || !rhs.isZero());
    } else if (!lhs.isNeg) {
        if (lhs.integerVal != rhs.integerVal) {
            return lhs.integerVal < rhs.integerVal;
        }
        for (int i = 0; i < decimal::len; i++) {
            if (lhs.dataArr[i] != rhs.dataArr[i]) {
                return lhs.dataArr[i] < rhs.dataArr[i];
            }
        }
        return false;
    } else {
        if (lhs.integerVal != rhs.integerVal) {
            return lhs.integerVal > rhs.integerVal;
        }
        for (int i = 0; i < decimal::len; i++) {
            if (lhs.dataArr[i] != rhs.dataArr[i]) {
                return lhs.dataArr[i] > rhs.dataArr[i];
            }
        }
        return false;
    }
}

bool operator>(const decimal &lhs, const decimal &rhs) {
    if (lhs.isNeg != rhs.isNeg) {
        return !lhs.isNeg && (!lhs.isZero() || !rhs.isZero());
    } else if (!lhs.isNeg) {
        if (lhs.integerVal != rhs.integerVal) {
            return lhs.integerVal > rhs.integerVal;
        }
        for (int i = 0; i < decimal::len; i++) {
            if (lhs.dataArr[i] != rhs.dataArr[i]) {
                return lhs.dataArr[i] > rhs.dataArr[i];
            }
        }
        return false;
    } else {
        if (lhs.integerVal != rhs.integerVal) {
            return lhs.integerVal < rhs.integerVal;
        }
        for (int i = 0; i < decimal::len; i++) {
            if (lhs.dataArr[i] != rhs.dataArr[i]) {
                return lhs.dataArr[i] < rhs.dataArr[i];
            }
        }
        return false;
    }
}

bool operator<=(const decimal &lhs, const decimal &rhs) {
    if (lhs.isNeg != rhs.isNeg) {
        return lhs.isNeg || (lhs.isZero() && rhs.isZero());
    } else if (!lhs.isNeg) {
        if (lhs.integerVal != rhs.integerVal) {
            return lhs.integerVal < rhs.integerVal;
        }
        for (int i = 0; i < decimal::len; i++) {
            if (lhs.dataArr[i] != rhs.dataArr[i]) {
                return lhs.dataArr[i] < rhs.dataArr[i];
            }
        }
        return true;
    } else {
        if (lhs.integerVal != rhs.integerVal) {
            return lhs.integerVal > rhs.integerVal;
        }
        for (int i = 0; i < decimal::len; i++) {
            if (lhs.dataArr[i] != rhs.dataArr[i]) {
                return lhs.dataArr[i] > rhs.dataArr[i];
            }
        }
        return true;
    }
}

bool operator>=(const decimal &lhs, const decimal &rhs) {
    if (lhs.isNeg != rhs.isNeg) {
        return !lhs.isNeg || (lhs.isZero() && rhs.isZero());
    } else if (!lhs.isNeg) {
        if (lhs.integerVal != rhs.integerVal) {
            return lhs.integerVal > rhs.integerVal;
        }
        for (int i = 0; i < decimal::len; i++) {
            if (lhs.dataArr[i] != rhs.dataArr[i]) {
                return lhs.dataArr[i] > rhs.dataArr[i];
            }
        }
        return true;
    } else {
        if (lhs.integerVal != rhs.integerVal) {
            return lhs.integerVal < rhs.integerVal;
        }
        for (int i = 0; i < decimal::len; i++) {
            if (lhs.dataArr[i] != rhs.dataArr[i]) {
                return lhs.dataArr[i] < rhs.dataArr[i];
            }
        }
        return true;
    }
}

bool operator==(const decimal &lhs, const decimal &rhs) {
    if (lhs.isZero() && rhs.isZero())
        return true;
    if (lhs.isNeg != rhs.isNeg)
        return false;
    if (lhs.integerVal != rhs.integerVal)
        return false;
    for (int i = 0; i < decimal::len; i++) {
        if (lhs.dataArr[i] != rhs.dataArr[i])
            return false;
    }
    return true;
}

bool operator!=(const decimal &lhs, const decimal &rhs) { return !(lhs == rhs); }

decimal &decimal::operator+=(long long rhs) {
    if (!isNeg) {
        if (integerVal + rhs >= 0) {
            integerVal += rhs;
        } else {
            bool lastFlag = false;
            for (int i = len - 1; i >= 0; i--) {
                if (lastFlag || dataArr[i]) {
                    dataArr[i] = mo - dataArr[i] - lastFlag;
                    lastFlag   = true;
                } else {
                    lastFlag = false;
                }
            }
            integerVal = -rhs - integerVal - lastFlag;
            isNeg      = true;
        }
    } else {
        if (integerVal - rhs >= 0) {
            integerVal -= rhs;
        } else {
            bool lastFlag = false;
            for (int i = len - 1; i >= 0; i--) {
                if (lastFlag || dataArr[i]) {
                    dataArr[i] = mo - dataArr[i] - lastFlag;
                    lastFlag   = true;
                } else {
                    lastFlag = false;
                }
            }
            integerVal = rhs - integerVal - lastFlag;
            isNeg      = false;
        }
    }
    return *this;
}

decimal &decimal::operator+=(int rhs) { return *this += (long long)rhs; }

decimal &decimal::operator-=(int rhs) { return *this += (long long)-rhs; }

decimal &decimal::operator-=(long long rhs) { return *this += -rhs; }

decimal &decimal::operator/=(int rhs) {
    if (rhs < 0) {
        isNeg ^= 1;
        rhs = -rhs;
    }

    int lastVal = integerVal % rhs;
    integerVal /= rhs;

    for (int i = 0; i < len; i++) {
        long long tmpVal = 1LL * lastVal * mo + dataArr[i];
        dataArr[i]       = tmpVal / rhs;
        lastVal          = tmpVal - 1LL * dataArr[i] * rhs;
    }

    if (isNeg && integerVal == 0) {
        int i;
        for (i = 0; i < len; i++) {
            if (dataArr[i] != 0) {
                break;
            }
        }
        if (i == len) {
            isNeg = false;
        }
    }

    return *this;
}

decimal &decimal::operator*=(int rhs) {
    if (rhs < 0) {
        isNeg ^= 1;
        rhs = -rhs;
    } else if (rhs == 0) {
        initZero();
        return *this;
    }

    int lastVal = 0;
    for (int i = len - 1; i >= 0; i--) {
        long long tmpVal = 1LL * dataArr[i] * rhs + lastVal;
        lastVal          = tmpVal / mo;
        dataArr[i]       = tmpVal - 1LL * lastVal * mo;
    }
    integerVal = integerVal * rhs + lastVal;

    return *this;
}

decimal operator-(const decimal &val) {
    decimal retVal = val;
    if (!retVal.isNeg && retVal.integerVal == 0) {
        int i;
        for (i = 0; i < decimal::len; i++) {
            if (retVal.dataArr[i] != 0)
                break;
        }
        if (i < decimal::len) {
            retVal.isNeg = true;
        }
    } else {
        retVal.isNeg ^= 1;
    }
    return retVal;
}

decimal operator+(const decimal &lhs, int rhs) {
    decimal retVal = lhs;
    return retVal += rhs;
}

decimal operator+(int lhs, const decimal &rhs) {
    decimal retVal = rhs;
    return retVal += lhs;
}

decimal operator+(const decimal &lhs, long long rhs) {
    decimal retVal = lhs;
    return retVal += rhs;
}

decimal operator+(long long lhs, const decimal &rhs) {
    decimal retVal = rhs;
    return retVal += lhs;
}

decimal operator-(const decimal &lhs, int rhs) {
    decimal retVal = lhs;
    return retVal -= rhs;
}

decimal operator-(int lhs, const decimal &rhs) { return -(rhs - lhs); }

decimal operator-(const decimal &lhs, long long rhs) {
    decimal retVal = lhs;
    return retVal -= rhs;
}

decimal operator-(long long lhs, const decimal &rhs) { return -(rhs - lhs); }

decimal operator*(const decimal &lhs, int rhs) {
    decimal retVal = lhs;
    return retVal *= rhs;
}

decimal operator*(int lhs, const decimal &rhs) {
    decimal retVal = rhs;
    return retVal *= lhs;
}

decimal operator/(const decimal &lhs, int rhs) {
    decimal retVal = lhs;
    return retVal /= rhs;
}

decimal operator+(const decimal &lhs, const decimal &rhs) {
    if (lhs.isNeg == rhs.isNeg) {
        decimal retVal   = lhs;
        bool    lastFlag = false;
        for (int i = decimal::len - 1; i >= 0; i--) {
            retVal.dataArr[i] += rhs.dataArr[i] + lastFlag;
            if (retVal.dataArr[i] >= decimal::mo) {
                retVal.dataArr[i] -= decimal::mo;
                lastFlag = true;
            } else {
                lastFlag = false;
            }
        }
        retVal.integerVal += rhs.integerVal + lastFlag;
        return retVal;
    } else if (!lhs.isNeg) {
        return lhs - -rhs;
    } else {
        return rhs - -lhs;
    }
}

decimal operator-(const decimal &lhs, const decimal &rhs) {
    if (!lhs.isNeg && !rhs.isNeg) {
        if (lhs >= rhs) {
            decimal retVal   = lhs;
            bool    lastFlag = false;
            for (int i = decimal::len - 1; i >= 0; i--) {
                retVal.dataArr[i] -= rhs.dataArr[i] + lastFlag;
                if (retVal.dataArr[i] < 0) {
                    retVal.dataArr[i] += decimal::mo;
                    lastFlag = true;
                } else {
                    lastFlag = false;
                }
            }
            retVal.integerVal -= rhs.integerVal + lastFlag;
            return retVal;
        } else {
            decimal retVal   = rhs;
            bool    lastFlag = false;
            for (int i = decimal::len - 1; i >= 0; i--) {
                retVal.dataArr[i] -= lhs.dataArr[i] + lastFlag;
                if (retVal.dataArr[i] < 0) {
                    retVal.dataArr[i] += decimal::mo;
                    lastFlag = true;
                } else {
                    lastFlag = false;
                }
            }
            retVal.integerVal -= lhs.integerVal + lastFlag;
            retVal.isNeg = true;
            return retVal;
        }
    } else if (lhs.isNeg && rhs.isNeg) {
        return -rhs - -lhs;
    } else if (lhs.isNeg) {
        return -(-lhs + rhs);
    } else {
        return lhs + -rhs;
    }
}

decimal operator+(const decimal &lhs, double rhs) { return lhs + decimal(rhs); }

decimal operator+(double lhs, const decimal &rhs) { return decimal(lhs) + rhs; }

decimal operator-(const decimal &lhs, double rhs) { return lhs - decimal(rhs); }

decimal operator-(double lhs, const decimal &rhs) { return decimal(lhs) - rhs; }

decimal &decimal::operator+=(double rhs) {
    *this = *this + decimal(rhs);
    return *this;
}

decimal &decimal::operator-=(double rhs) {
    *this = *this - decimal(rhs);
    return *this;
}

decimal &decimal::operator+=(const decimal &rhs) {
    *this = *this + rhs;
    return *this;
}

decimal &decimal::operator-=(const decimal &rhs) {
    *this = *this - rhs;
    return *this;
}
}   // namespace bigNum

constexpr int maxN = 1e5 + 5;
int           n, m, k, p;
int           heights[maxN];
int           preSum[maxN];
double        dpF[15][maxN];
int           dpG[15][maxN];

struct pointNode {
    int    posX;
    double posY;
    pointNode(int initX = 0, double initY = 0)
        : posX(initX)
        , posY(initY) {}
} pts[maxN];

int que[maxN], hd, tl;

inline double calcSlope(pointNode lhs, pointNode rhs) { return (lhs.posY - rhs.posY) / (lhs.posX - rhs.posX); }

inline bigNum::decimal calcResult(int j, int i) {
    if (!j)
        return heights[1];
    return (calcResult(j - 1, dpG[j][i]) + preSum[i] - preSum[dpG[j][i]]) / (i - dpG[j][i] + 1);
}

int main() {
    scanf("%d%d%d%d", &n, &m, &p, &heights[1]);
    int newN = 1;
    for (int i = 2; i <= n; ++i) {
        int xVal;
        scanf("%d", &xVal);
        if (xVal >= heights[1]) {
            heights[++newN] = xVal;
        }
    }
    n = newN;
    m = min(m, n);
    k = min(m, 14);

    sort(heights + 2, heights + 1 + n);

    for (int i = 1; i <= n; ++i) {
        preSum[i] = preSum[i - 1] + heights[i];
        dpF[0][i] = heights[1];
    }

    for (int j = 1; j <= k; ++j) {
        for (int i = 1; i <= n; ++i) {
            pts[i] = pointNode(i - 1, preSum[i] - dpF[j - 1][i]);
        }
        hd     = 1;
        tl     = 1;
        que[1] = 1;
        for (int i = 2; i <= n; ++i) {
            pointNode currNode = pointNode(i, preSum[i]);
            while (hd < tl && calcSlope(currNode, pts[que[hd]]) < calcSlope(currNode, pts[que[hd + 1]])) {
                hd++;
            }
            dpF[j][i] = (dpF[j - 1][que[hd]] + preSum[i] - preSum[que[hd]]) / (i - que[hd] + 1);
            dpG[j][i] = que[hd];
            while (hd < tl && calcSlope(pts[que[tl - 1]], pts[que[tl]]) > calcSlope(pts[que[tl]], pts[i])) {
                tl--;
            }
            que[++tl] = i;
        }
    }

    int oVal = n - m + k;
    int uVal = 0;
    for (int i = 0; i <= k; i++) {
        if (dpF[i][oVal] > dpF[uVal][oVal]) {
            uVal = i;
        }
    }

    bigNum::decimal finalAns = calcResult(uVal, oVal);
    for (int i = oVal + 1; i <= n; ++i) {
        finalAns = (finalAns + heights[i]) / 2;
    }

    printf("%s\n", finalAns.toString(p << 1).c_str());
    return 0;
}
