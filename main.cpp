#include "Configuration.h"
#include "utils.h"

int main() {
    Configuration conf(100, 4);
    // Register the GUI
    // You can specify the dimensions of the window
    RuntimeGUI gui(1000, 1200);
    gui.waitTime = 7;
    gui.notify(conf);

    static const int runs = 10000;

    for (int i = 0; i < runs; i++) {
        if (i % 1 == 0) {
            conf.addSand();
        }
        conf.runTime();
        if (i % 10 == 0) {
            gui.notify(conf);
            gui.saveImageToDisk(i, "./results/");
        }
    }
    cv::waitKey(0);
    cv::destroyAllWindows();
}
