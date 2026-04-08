class Robot {
public:
    int w, h;
    int x = 0, y = 0;
    int dir = 0; 
    int perimeter;
    bool started = false;

    vector<string> directions = {"East", "North", "West", "South"};

    Robot(int width, int height) {
        w = width;
        h = height;
        perimeter = 2 * (w + h) - 4;
    }

    void step(int num) {
        if (perimeter == 0) return;

        num %= perimeter;
        if (!started && num == 0) {
            dir = 3;
            return;
        }

        started = true;

        while (num > 0) {
            if (dir == 0) { 
                int move = min(num, w - 1 - x);
                x += move;
                num -= move;
                if (x == w - 1 && num > 0) dir = 1;
            }
            else if (dir == 1) { 
                int move = min(num, h - 1 - y);
                y += move;
                num -= move;
                if (y == h - 1 && num > 0) dir = 2;
            }
            else if (dir == 2) { 
                int move = min(num, x);
                x -= move;
                num -= move;
                if (x == 0 && num > 0) dir = 3;
            }
            else { 
                int move = min(num, y);
                y -= move;
                num -= move;
                if (y == 0 && num > 0) dir = 0;
            }
        }
    }

    vector<int> getPos() {
        return {x, y};
    }

    string getDir() {
        return directions[dir];
    }
};
