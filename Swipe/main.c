#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#define SCRIPT_VERSION "1.0 [ Build Touch SETTINGS ]"

// Function to display a notification
void shell(const char *message) {
    char command[512];
    snprintf(command, sizeof(command),
             "cmd notification post -S bigtext -t '♨️ Velocity Finger ' 'Tag' '%s' > /dev/null 2>&1",
             message);
    system(command);
}

// Function to set the touch settings - Brutal Mode
void touchBrutal() {
    char commands[1024];

    snprintf(commands, sizeof(commands),  
        "settings put global window_animation_scale 0.25 && "
        "settings put global transition_animation_scale 0.25 && "
        "settings put global animator_duration_scale 0.25 && "
        "settings put secure long_press_timeout 100 && "
        "settings put secure multi_press_timeout 150 && "
        "settings put secure display_density_forced 520 && "
        "settings put system tap_duration 20 && "
        "settings put system view.scroll_friction 3 && "
        "settings put secure pointer_speed 10 && "
        "input gamepad swipe 200 500 600 500 30 && "
        "input touchpad swipe 200 500 300 500 70 && "
        "input touchscreen swipe 100 100 500 500 150 && "
        "input swipe 500 1000 900 1000 30 && "
        "input gamepad tap 250 450 && "
        "input touchpad tap 350 650 && "
        "input touchscreen tap 130 180 && "
        "input tap 750 1150");

    int result = system(commands);
    if (result != 0) {
        printf("Error: Failed to apply Brutal settings.\n");
        return;
    }

    shell("Successfully applied Brutal settings Velocity Finger");
    printf("\n\t=== Velocity Finger: Brutal Mode ===\n");
    printf("Mode ini mengoptimalkan kecepatan sentuhan secara ekstrem.\n");
    printf("- Animasi sistem dipercepat hingga 0.25x\n");
    printf("- Timeout sentuhan dipersingkat untuk respons cepat\n");
    printf("- Kecepatan pointer maksimum (10)\n");
    printf("- Refresh rate disesuaikan dengan performa tertinggi\n");
    printf("- Mengatur beberapan Configurasi input \n\n");    

}

// Function to set the touch settings - Medium Mode
void touchMedium() {
    char commands[1024];

    snprintf(commands, sizeof(commands),  
        "settings put global window_animation_scale 0.40 && "
        "settings put global transition_animation_scale 0.40 && "
        "settings put global animator_duration_scale 0.40 && "
        "settings put secure long_press_timeout 180 && "
        "settings put secure display_density_forced 460 &&"
        "settings put secure multi_press_timeout 220 && "
        "settings put system tap_duration 60 && "
        "settings put system view.scroll_friction 20 && "
        "settings put secure pointer_speed 6 && "
        "input gamepad swipe 200 500 600 500 50 && "
        "input touchpad swipe 200 500 300 500 90 && "
        "input touchscreen swipe 100 100 500 500 180 && "
        "input swipe 500 1000 900 1000 45 && "
        "input gamepad tap 280 480 && "
        "input touchpad tap 370 670 && "
        "input touchscreen tap 140 190 && "
        "input tap 770 1180");

    int result = system(commands);
    if (result != 0) {
        printf("Error: Failed to apply Medium settings.\n");
        return;
    }

    shell("Successfully applied Medium settings Velocity Finger");
    printf("\n\t=== Velocity Finger: Medium Mode ===\n");
    printf("Mode ini memberikan keseimbangan antara respons dan kenyamanan.\n");
    printf("- Animasi sistem dikurangi hingga 0.40x\n");
    printf("- Timeout sentuhan diatur untuk kecepatan dan akurasi\n");
    printf("- Kecepatan pointer sedang (6)\n");
    printf("- Refresh rate optimal untuk kelancaran UI\n");
}

// Function to reset refresh rate settings
void Deltouch() {
    char commands[512];

    snprintf(commands, sizeof(commands),
        "settings put global window_animation_scale 0.5 && "
        "settings put global transition_animation_scale 0.5 && "
        "settings put global animator_duration_scale 0.5 && "
        "settings put secure long_press_timeout 300 && "
        "settings put secure multi_press_timeout 300 && "
        "settings delete system tap_duration && "
        "settings delete system view.scroll_friction && "
        "settings delete secure display_density_forced && "
        "settings put secure pointer_speed 3");

    int result = system(commands);
    if (result != 0) {
        printf("Error: Failed to reset refresh rate settings.\n");
        return;
    }

    shell("Velocity Finger scripting success Delete");
    printf("Success: Velocity Finger reset to default settings.\n");
}

// Function to display usage instructions
void Usage() {
    printf("\nVelocity Finger %s - Lightweight System Utility\n\n", SCRIPT_VERSION);
    printf("SYNOPSIS:\n");
    printf("  Velocity Finger [OPTIONS]\n\n");
    printf("DESCRIPTION:\n");
    printf("  Velocity Finger is a lightweight system utility designed to dynamically\n");
    printf("  adjust the device's touch responsiveness and animation settings.\n\n");
    printf("OPTIONS:\n");
    printf("  -E    Apply Brutal Touch Optimization\n");
    printf("  -l    Apply Medium Touch Optimization\n");
    printf("  -d    Reset touch settings to default\n");
    printf("  -h    Display this help message\n\n");
    printf("EXAMPLES:\n");
    printf("  Apply Brutal Touch Optimization:\n");
    printf("      Velocity Finger -E\n");
    printf("Use this mode if you want the best touch performance!\n\n");
    printf("  Apply Medium Touch Optimization:\n");
    printf("      Velocity Finger -l\n");
    printf("This mode is recommended for daily use.\n\n"); 
    printf("  Reset touch settings:\n");
    printf("      Velocity Finger -d\n");
    printf("Use this mode if you want to restore to the initial settings.\n\n"); 
    printf("SEE ALSO:\n");
    printf("  ADB Commands - https://developer.android.com/studio/command-line/adb\n");
    printf("  Android Settings Provider - https://developer.android.com/reference/android/provider/Settings\n");
    printf("\n");
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        Usage();
    }

    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-E") == 0) {  
            sleep(1);
            touchBrutal();
        } else if (strcmp(argv[i], "-l") == 0) { 
            sleep(1);
            touchMedium();
        } else if (strcmp(argv[i], "-d") == 0) {
            Deltouch();
        } else if (strcmp(argv[i], "-h") == 0) {
            Usage();
        } else {  
            printf("Unknown option: %s\n", argv[i]);  
            Usage();  
        }  
    }

    sleep(1);
    printf("\n");
    printf(" ⚠️ This module is protected by copyright and is\n");
    printf(" intended for use by regular users only. Any use of\n");
    printf(" this module, including its code, design, or features,\n");
    printf(" by other developers without written permission from\n");
    printf(" the copyright owner is strictly prohibited.\n");
    printf("______________________________________________(+)\n\n");  

    return 0;
}