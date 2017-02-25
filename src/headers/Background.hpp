#ifndef BACKGROUND_H_
#define BACKGROUND_H_

#define MAX_NUM_STARS 100
#define STAR_SPEED 5

typedef struct {
    double x, y;
    double vx, vy; // vektori pravca kretanja zvezde
} Star;

class Background {

    private:
        Star stars[MAX_NUM_STARS];
    
    private:
        void initStars();
        void renderStars();
        void updateStars();
    public:
        Background();
        ~Background();
        void render2D();
        void render3D();
        void update();

};

#endif