#include "pico/stdlib.h"
#include "FreeRTOS.h"
#include "task.h"

#define LED_RED    2
#define LED_GREEN  3
#define LED_BLUE   4
#define BUZZER     5
#define BUTTON_A   6
#define BUTTON_B   7

TaskHandle_t ledTaskHandle = NULL;
TaskHandle_t buzzerTaskHandle = NULL;

void led_task(void *pvParameters) {
    while (1) {
        gpio_put(LED_RED, 1); gpio_put(LED_GREEN, 0); gpio_put(LED_BLUE, 0);
        vTaskDelay(pdMS_TO_TICKS(500));
        gpio_put(LED_RED, 0); gpio_put(LED_GREEN, 1); gpio_put(LED_BLUE, 0);
        vTaskDelay(pdMS_TO_TICKS(500));
        gpio_put(LED_RED, 0); gpio_put(LED_GREEN, 0); gpio_put(LED_BLUE, 1);
        vTaskDelay(pdMS_TO_TICKS(500));
    }
}

void buzzer_task(void *pvParameters) {
    while (1) {
        gpio_put(BUZZER, 1);
        vTaskDelay(pdMS_TO_TICKS(100));
        gpio_put(BUZZER, 0);
        vTaskDelay(pdMS_TO_TICKS(900));
    }
}

void buttons_task(void *pvParameters) {
    bool ledSuspended = false;
    bool buzzerSuspended = false;

    while (1) {
        if (gpio_get(BUTTON_A) == 0 && !ledSuspended) {
            vTaskSuspend(ledTaskHandle);
            ledSuspended = true;
        } else if (gpio_get(BUTTON_A) != 0 && ledSuspended) {
            vTaskResume(ledTaskHandle);
            ledSuspended = false;
        }

        if (gpio_get(BUTTON_B) == 0 && !buzzerSuspended) {
            vTaskSuspend(buzzerTaskHandle);
            buzzerSuspended = true;
        } else if (gpio_get(BUTTON_B) != 0 && buzzerSuspended) {
            vTaskResume(buzzerTaskHandle);
            buzzerSuspended = false;
        }

        vTaskDelay(pdMS_TO_TICKS(100));
    }
}

int main() {
    stdio_init_all();

    gpio_init(LED_RED);   gpio_set_dir(LED_RED, GPIO_OUT);
    gpio_init(LED_GREEN); gpio_set_dir(LED_GREEN, GPIO_OUT);
    gpio_init(LED_BLUE);  gpio_set_dir(LED_BLUE, GPIO_OUT);
    gpio_init(BUZZER);    gpio_set_dir(BUZZER, GPIO_OUT);

    gpio_init(BUTTON_A);  gpio_set_dir(BUTTON_A, GPIO_IN); gpio_pull_up(BUTTON_A);
    gpio_init(BUTTON_B);  gpio_set_dir(BUTTON_B, GPIO_IN); gpio_pull_up(BUTTON_B);

    xTaskCreate(led_task, "LED", 256, NULL, 1, &ledTaskHandle);
    xTaskCreate(buzzer_task, "Buzzer", 256, NULL, 1, &buzzerTaskHandle);
    xTaskCreate(buttons_task, "Buttons", 256, NULL, 1, NULL);

    vTaskStartScheduler();

    while (1);  
}
