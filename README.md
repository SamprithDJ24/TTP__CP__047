<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Timetable Management System</title>
</head>
<body>

<h1>Timetable Management System</h1>

<h2>Description</h2>

<p>This C program is a simple Timetable Management System that allows users to create and manage a timetable for subjects over a specified number of days and slots. Users can add subjects, schedule them randomly, display the timetable, change subject slots, or delete subjects. The program is designed to work with a fixed number of days and slots per day.</p>

<h2>Features</h2>

<ul>
    <li>Add subjects and schedule them randomly.</li>
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

<h2>How to Use</h2>

<ol>
    <li>Clone this Git repository to your local machine:</li>
    <code>git clone &lt;repository_url&gt;</code>

    <li>Navigate to the project directory:</li>
    <code>cd timetable-management-system</code>

    <li>Compile the program using your C compiler. For example, using GCC:</li>
    <code>gcc timetable.c -o timetable</code>

    <li>Run the program:</li>
    <code>./timetable</code>

    <li>Follow the on-screen instructions to use the program:</li>
    <ul>
        <li>Enter the number of working days in a week.</li>
        <li>Enter the number of slots per day.</li>
    </ul>
</ol>

<h2>Menu Options</h2>

<ul>
    <li><strong>Add subjects and schedule (Option 1)</strong>:
        <ul>
            <li>Allows you to add subjects and schedule them randomly on the timetable.</li>
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

<h2>License</h2>

<p>This project is licensed under the MIT License - see the <a href="LICENSE">LICENSE</a> file for details.</p>

<h2>Author</h2>

<p>[Your Name]</p>

</body>
</html>
