/* main1.c */
#include <stdio.h>
#include <dlfcn.h>


int main(){

    void *lib_handle;
    double (*calc_add)(double, double);
    double (*calc_sub)(double, double);
    double (*calc_mul)(double, double);
    double (*calc_div)(double, double);
    const char *error_msg;

    lib_handle = dlopen("./libcalc.so", RTLD_LAZY);
    if (!lib_handle) {
        fprintf(stderr, "Error loading library: %s\n", dlerror());
        return 1;
    }

    calc_add = dlsym(lib_handle, "calc_add");
    error_msg = dlerror();
    if (error_msg) {
        fprintf(stderr, "Error loading symbol calc_add: %s\n", error_msg);
        return 1;
    }

    calc_sub = dlsym(lib_handle, "calc_sub");
    error_msg = dlerror();
    if (error_msg) {
        fprintf(stderr, "Error loading symbol calc_sub: %s\n", error_msg);
        return 1;
    }

    calc_mul = dlsym(lib_handle, "calc_mul");
    error_msg = dlerror();
    if (error_msg) {
        fprintf(stderr, "Error loading symbol calc_mul: %s\n", error_msg);
        return 1;
    }

    calc_div = dlsym(lib_handle, "calc_div");
    error_msg = dlerror();
    if (error_msg) {
        fprintf(stderr, "Error loading symbol calc_div: %s\n", error_msg);
        return 1;
    }

    printf("calc_add(10, 4) = %.2f\n", (*calc_add)(10, 4));
    printf("calc_sub(10, 4) = %.2f\n", (*calc_sub)(10, 4));
    printf("calc_mul(10, 4) = %.2f\n", (*calc_mul)(10, 4));
    printf("calc_div(10, 4) = %.2f\n", (*calc_div)(10, 4));
    printf("calc_div(10, 0) = %.2f  /* cant divide by zero */\n",(*calc_div)(10, 0));

    dlclose(lib_handle);    
    return 0;

}
    
