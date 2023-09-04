<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
</head>
<body>

<h1>Student TimeTable Generator</h1>

<h2>Description</h2>

<p>This C program is a simple Timetable Management System that allows users to create and manage a timetable for subjects over a specified number of days and slots. Users can add subjects, schedule them randomly, display the timetable, change subject slots, or delete subjects. The program is designed to work with a fixed number of days and slots per day.</p>

<h2>Features</h2>

<ul>
    <li>Add subjects and schedule time-table systematically.</li>
    <li>Display the timetable in a tabular format.</li>
    <li>Change the slot of a subject on a specific day.</li>
    <li>Delete a subject from a specific slot on a specific day.</li>
</ul>

<h2>Requirements</h2>

<p>To run this program, you need:</p>

<ul>
    <li>A C compiler (e.g., GCC)</li>
    <li>Standard C libraries</li>
</ul>



<h2>Menu Options</h2>

<ul>
    <li><strong>Add subjects and schedule (Option 1)</strong>:
        <ul>
            <li>Allows you to add subjects and schedule them systematically on the timetable.</li>
            <li>Ensures that each subject appears at least once a day.</li>
            <li>Subjects are randomly assigned to available slots.</li>
        </ul>
    </li>
<li><strong>Display timetable (Option 2)</strong>:
        <ul>
            <li>Displays the current timetable in a tabular format.</li>
        </ul>
    </li>

<li><strong>Change subject slot (Option 3)</strong>:
        <ul>
            <li>Allows you to change the slot of a subject on a specific day.</li>
            <li>Enter the day and slot to change and provide the new subject name.</li>
        </ul>
    </li>

 <li><strong>Delete subject (Option 4)</strong>:
        <ul>
            <li>Allows you to delete a subject from a specific slot on a specific day.</li>
            <li>Enter the day and slot to delete the subject from.</li>
        </ul>
    </li>

 <li><strong>Exit (Option 5)</strong>:
        <ul>
            <li>Exits the program.</li>
        </ul>
    </li>
    
</ul>

<h2>Selected Functions</h2>

<h3>displayTimetable Function</h3>

<p>The <code>displayTimetable</code> function is used to display the current timetable in a tabular format. It takes the <code>timetable</code> array, the number of <code>days</code>, and the number of <code>slots</code> as arguments.</p>

<h3>isSubjectScheduledTodayInArray Function</h3>

<p>The <code>isSubjectScheduledTodayInArray</code> function checks if a subject is scheduled on a specific day. It takes an array of scheduled subjects, the day index, the subject name, and the number of subjects as arguments.</p>

<h3>addSubjectsAndSchedule Function</h3>

<p>The <code>addSubjectsAndSchedule</code> function is responsible for adding subjects and scheduling them randomly on the timetable. It ensures that each subject appears at least once a day and subjects are randomly assigned to available slots.</p>

<h3>changeSubjectSlot Function</h3>

<p>The <code>changeSubjectSlot</code> function allows the user to change the slot of a subject on a specific day. It takes the day, slot, and the new subject name as arguments.</p>

<h3>deleteSubject Function</h3>

<p>The <code>deleteSubject</code> function allows the user to delete a subject from a specific slot on a specific day. It takes the day and slot to delete the subject from.</p>

</body>
</html>
