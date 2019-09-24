#ifndef _BM_H
#define _BM_H

#include <vector>
#include <mutex>

class BM {
private: 
    BM() {}

public:
    static BM* instance() {
        if (_instance != nullptr) {
            return _instance;
        }

        std::lock_guard<std::mutex> lk(tx);
        _instance = new BM;
        return _instance;
    }
    int bm(char* a, int n, char* b, int m) {
        std::vector<char> bc(SIZE, -1);
        generateBC(b, m, bc);
        std::vector<int> suffix(m, -1);
        std::vector<bool> prefix(m, false);
        generatrGS(b, m, suffix, prefix);
        int i = 0;
        while (i < n - m + 1) {
            int j;
            for (j = m-1; j >= 0; --j) {
                if (a[i+j] != b[j]) break;
            }
            if (j < 0) {
                return i;
            }
            int x = j - bc[(int)a[i+j]];
            int y = 0;
            if (j < m-1) {
                y = moveByGS(j, m, suffix, prefix);
            }
            i += max(x, y);
        }

        return -1;
    }

private:
    void generateBC(char* b, int m, std::vector<char>& bc) {
        for (int i = 0; i < m; ++i) {
            int ascii = (int)b[i];
            bc[ascii] = i;
        }
    }

    void generatrGS(char* b, int m, std::vector<int>& suffix, std::vector<bool>& prefix) {
        for (int i = 0; i < m-1; ++i) {
            int j = i;
            int k = 0;
            while (j >= 0 && b[j] == b[m-1-k]) {
                --j;
                ++k;
                suffix[k] = j+1;
            }
            if (j == -1) prefix[k] = true;
        }
    }

    int moveByGS(int j, int m, std::vector<int>& suffix, std::vector<bool>& prefix) {
        int k = m - 1 - j;
        if (suffix[k] != -1) return j - suffix[k] + 1;
        for (int r = j+2; r <= m-1; ++r) {
            if (prefix[m-r] = true) return r;
        }
        return m;
    }

    int max(int a, int b) {
        return a > b ? a : b;
    }

private:
    const static int SIZE = 256; 
    static BM* _instance;
    static std::mutex tx;
};

BM* BM::_instance = nullptr;
std::mutex BM::tx;

#endif