class Spreadsheet {
private:
    vector<vector<int>> grid;

public:
    Spreadsheet(int rows) {
        grid.resize(rows);
        for (auto& it : grid) {
            it.resize(26, 0);
        }
    }

    void setCell(string cell, int value) {
        int c = cell[0] - 'A';
        string s = cell.substr(1, cell.size() - 1);
        int r = stoi(s) - 1;
        grid[r][c] = value;
    }

    void resetCell(string cell) {
        int c = cell[0] - 'A';
        string s = cell.substr(1, cell.size() - 1);
        int r = stoi(s) - 1;
        grid[r][c] = 0;
    }

    int getValue(string formula) {
        int idx1, idx2;
        for (int i = 0; i < formula.size(); i++) {
            if (formula[i] == '=') {
                idx1 = i + 1;
            } else if (formula[i] == '+') {
                idx2 = i + 1;
            }
        }
        int c;
        int r;
        int a, b;
        if (formula[idx1] >= 'A' && formula[idx1] <= 'Z') {
            c = formula[idx1] - 'A';
            string s = formula.substr(idx1 + 1, idx2 - idx1);
            r = stoi(s) - 1;
            a = grid[r][c];
        } else {
            string s = formula.substr(idx1, idx2 - idx1 + 1);
            a = stoi(s);
        }

        if (formula[idx2] >= 'A' && formula[idx2] <= 'Z') {
            c = formula[idx2] - 'A';
            string s = formula.substr(idx2 + 1, formula.size() - 1 - idx2);
            r = stoi(s) - 1;
            b = grid[r][c];
        } else {
            string s = formula.substr(idx2, formula.size() - 1 - idx2 + 1);
            b = stoi(s);
        }
        return a + b;
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */