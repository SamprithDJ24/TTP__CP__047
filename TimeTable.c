#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_COURSES 10
#define MAX_DAYS 5 // Adjusted for a 5-day school week (Monday to Friday)
#define MAX_SLOTS_PER_DAY 6 // Adjusted for 6 time slots per day

typedef struct {
    char name[50];
    int duration;
} Course;

typedef struct {
    char name[50]; // Course name added to timetable entry
    char day[10];
    int slot;
} TimetableEntry;

// Function prototypes
void generateTimetable(Course courses[], int numCourses);
int isSlotAvailable(TimetableEntry timetable[][MAX_SLOTS_PER_DAY], int day, int slot, int duration, const char *courseName);
void addToTimetable(TimetableEntry timetable[][MAX_SLOTS_PER_DAY], Course course, int day, int slot);
void shuffleCourses(Course courses[], int numCourses);
void displayTimetable(TimetableEntry timetable[][MAX_SLOTS_PER_DAY]);

int main() {
    Course courses[MAX_COURSES];
    int numCourses;

    printf("Enter the number of courses: ");
    scanf("%d", &numCourses);
    getchar();

    printf("Enter course details:\n");
    for (int i = 0; i < numCourses; i++) {
        printf("Course %d name: ", i + 1);
        fgets(courses[i].name, sizeof(courses[i].name), stdin);
        courses[i].name[strlen(courses[i].name) - 1] = '\0'; // Remove newline character

        printf("Course %d duration (in time slots): ", i + 1);
        scanf("%d", &courses[i].duration);
        getchar(); // Consume newline character
    }

    generateTimetable(courses, numCourses);

    return 0;
}

void generateTimetable(Course courses[], int numCourses) {
    TimetableEntry timetable[MAX_DAYS][MAX_SLOTS_PER_DAY] = {0}; // Initialize all elements to 0

    // Shuffle the order of courses randomly
    shuffleCourses(courses, numCourses);

    int day = 0;
    int slot = 0;
    for (int i = 0; i < numCourses; i++) {
        while (!isSlotAvailable(timetable, day, slot, courses[i].duration, courses[i].name)) {
            slot++;
            if (slot >= MAX_SLOTS_PER_DAY) {
                slot = 0;
                day++;
                if (day >= MAX_DAYS) {
                    printf("Timetable cannot be generated due to constraints.\n");
                    return;
                }
            }
        }
        addToTimetable(timetable, courses[i], day, slot);
        slot += courses[i].duration;
        if (slot >= MAX_SLOTS_PER_DAY) {
            slot = 0;
            day++;
            if (day >= MAX_DAYS) {
                printf("Timetable cannot be generated due to constraints.\n");
                return;
            }
        }
    }

    displayTimetable(timetable);
}

int isSlotAvailable(TimetableEntry timetable[][MAX_SLOTS_PER_DAY], int day, int slot, int duration, const char *courseName) {
    for (int i = 0; i < duration; i++) {
        if (timetable[day][slot + i].name[0] != '\0' || strcmp(timetable[day][slot + i].name, courseName) == 0) {
            return 0;
        }
    }
    return 1;
}

void addToTimetable(TimetableEntry timetable[][MAX_SLOTS_PER_DAY], Course course, int day, int slot) {
    for (int i = 0; i < course.duration; i++) {
        strcpy(timetable[day][slot + i].name, course.name);
        strcpy(timetable[day][slot + i].day, "Day");
        timetable[day][slot + i].slot = slot + i;
    }
}

void shuffleCourses(Course courses[], int numCourses) {
    srand(time(NULL)); // Seed the random number generator
    for (int i = numCourses - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        Course temp = courses[i];
        courses[i] = courses[j];
        courses[j] = temp;
    }
}

void displayTimetable(TimetableEntry timetable[][MAX_SLOTS_PER_DAY]) {
    printf("\nGenerated Timetable:\n");

    printf("+------------+------+------+------+------+------+\n");
    printf("| Time Slots | Mon  | Tue  | Wed  | Thu  | Fri  |\n");
    printf("+------------+------+------+------+------+------+\n");

    for (int s = 0; s < MAX_SLOTS_PER_DAY; s++) {
        printf("| Slot %2d   |", s);
        for (int d = 0; d < MAX_DAYS; d++) {
            if (timetable[d][s].name[0] != '\0') {
                printf(" %-4s |", timetable[d][s].name);
            } else {
                printf("      |");
            }
        }
        printf("\n+------------+------+------+------+------+------+\n");
    }
}
