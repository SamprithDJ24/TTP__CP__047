#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_SUBJECTS 10
#define MAX_DAYS 5
#define MAX_SLOTS 6
#define SUBJECT_NAME_LENGTH 50

typedef struct {
    char name[SUBJECT_NAME_LENGTH];
    int slotsPerDay[MAX_DAYS];
} Subject;

void displayTimetable(Subject timetable[MAX_DAYS][MAX_SLOTS], int days, int slots) {
    printf("\n--- Timetable ---\n");
    printf("%-15s", "Day/Slot");
    for (int slot = 1; slot <= slots; ++slot) {
        printf("| Slot %d", slot);
    }
    printf("\n--------------------------------------\n");
    for (int day = 0; day < days; ++day) {
        printf("%-15s", day == 0 ? "Monday" : day == 1 ? "Tuesday" : day == 2 ? "Wednesday" : day == 3 ? "Thursday" : "Friday");
        for (int slot = 0; slot < slots; ++slot) {
            printf("| %-6s", timetable[day][slot].name);
        }
        printf("\n");
    }
    printf("--------------------------------------\n");
}

int isSubjectScheduledTodayInArray(const char scheduledSubjects[MAX_SUBJECTS][MAX_DAYS][SUBJECT_NAME_LENGTH], int day, const char *subjectName, int numSubjects) {
    for (int subjectIndex = 0; subjectIndex < numSubjects; ++subjectIndex) {
        if (strcmp(scheduledSubjects[subjectIndex][day], subjectName) == 0) {
            return 1;
        }
    }
    return 0;
}

int main() {
    Subject timetable[MAX_DAYS][MAX_SLOTS];
    int days, slots;
    int choice;

    printf("Enter the number of days in a week: ");
    scanf("%d", &days);

    printf("Enter the number of slots per day: ");
    scanf("%d", &slots);

    if (days <= 0 || slots <= 0) {
        printf("Invalid input for days/slots.\n");
        return 1;
    }

    srand(time(NULL));

    for (int day = 0; day < days; ++day) {
        for (int slot = 0; slot < slots; ++slot) {
            strcpy(timetable[day][slot].name, "Free");
            timetable[day][slot].slotsPerDay[day] = 0;
        }
    }

    do {
        printf("\n--- Menu ---\n");
        printf("1. Add subjects and schedule\n");
        printf("2. Display timetable\n");
        printf("3. Change subject slot\n");
        printf("4. Delete subject\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: // Add subjects and schedule
    printf("Enter the number of subjects: ");
    int numSubjects;
    scanf("%d", &numSubjects);

    if (numSubjects > MAX_SUBJECTS) {
        printf("Maximum subjects allowed: %d\n", MAX_SUBJECTS);
        break;
    }

    char scheduledSubjects[MAX_DAYS][MAX_SUBJECTS][SUBJECT_NAME_LENGTH] = {0}; // To track subjects scheduled on each day
    int scheduledCounts[MAX_DAYS][MAX_SUBJECTS] = {0}; // To track the count of subjects scheduled on each day

    for (int i = 0; i < numSubjects; ++i) {
        printf("Enter subject name: ");
        char newSubjectName[SUBJECT_NAME_LENGTH];
        scanf("%s", newSubjectName);

        printf("Enter total number of slots for subject %s: ", newSubjectName);
        int totalSlots;
        scanf("%d", &totalSlots);

        int availableSlots = days * slots;

        if (totalSlots <= availableSlots) {
            int slotsAdded = 0;

            // Shuffle the order of days and slots
            int shuffledDays[MAX_DAYS];
            for (int i = 0; i < days; ++i) {
                shuffledDays[i] = i;
            }
            srand(time(NULL));
            for (int i = days - 1; i > 0; --i) {
                int j = rand() % (i + 1);
                int temp = shuffledDays[i];
                shuffledDays[i] = shuffledDays[j];
                shuffledDays[j] = temp;
            }

            int shuffledSlots[MAX_SLOTS];
            for (int i = 0; i < slots; ++i) {
                shuffledSlots[i] = i;
            }
            for (int i = slots - 1; i > 0; --i) {
                int j = rand() % (i + 1);
                int temp = shuffledSlots[i];
                shuffledSlots[i] = shuffledSlots[j];
                shuffledSlots[j] = temp;
            }

            for (int dayIdx = 0; dayIdx < days && slotsAdded < totalSlots; ++dayIdx) {
                int day = shuffledDays[dayIdx];

                // Ensure the subject appears at least once a day
                int slotIdx = rand() % slots;
                int slot = shuffledSlots[slotIdx];

                if (scheduledCounts[day][i] < 2 && !isSubjectScheduledTodayInArray(scheduledSubjects, day, newSubjectName, numSubjects)) {
                    if (strcmp(timetable[day][slot].name, "Free") == 0) {
                        strcpy(timetable[day][slot].name, newSubjectName);
                        timetable[day][slot].slotsPerDay[day]++;
                        strcpy(scheduledSubjects[day][slotsAdded], newSubjectName);
                        scheduledCounts[day][i]++;
                        slotsAdded++;
                    }
                }
            }

            printf("Subject %s added to %d random slots.\n", newSubjectName, slotsAdded);
        } else {
            printf("Not enough available slots to add subject %s.\n", newSubjectName);
        }
    }
    break;



            case 2: // Display timetable
                displayTimetable(timetable, days, slots);
                break;

            case 3: // Change subject slot
                printf("Enter day and slot to change (e.g., 2 3): ");
                int changeDay, changeSlot;
                scanf("%d %d", &changeDay, &changeSlot);

                if (changeDay >= 1 && changeDay <= days && changeSlot >= 1 && changeSlot <= slots) {
                    printf("Enter new subject name: ");
                    char updatedSubjectName[SUBJECT_NAME_LENGTH];
                    scanf("%s", updatedSubjectName);

                    strcpy(timetable[changeDay - 1][changeSlot - 1].name, updatedSubjectName);
                    printf("Subject updated in Day %d Slot %d.\n", changeDay, changeSlot);
                } else {
                    printf("Invalid day or slot.\n");
                }
                break;

            case 4: // Delete subject
                printf("Enter day and slot to delete (e.g., 2 3): ");
                int deleteDay, deleteSlot;
                scanf("%d %d", &deleteDay, &deleteSlot);

                if (deleteDay >= 1 && deleteDay <= days && deleteSlot >= 1 && deleteSlot <= slots) {
                    strcpy(timetable[deleteDay - 1][deleteSlot - 1].name, "Free");
                    timetable[deleteDay - 1][deleteSlot - 1].slotsPerDay[deleteDay - 1]--;
                    printf("Subject deleted from Day %d Slot %d.\n", deleteDay, deleteSlot);
                } else {
                    printf("Invalid day or slot.\n");
                }
                break;

            case 5: // Exit
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice. Please select a valid option.\n");
        }

    } while (choice != 5);

    return 0;
}

