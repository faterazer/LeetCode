char* dayOfTheWeek(int day, int month, int year)
{
    if (month < 3) {
        month = 12 + month;
        year--;
    }
    int c = year / 100, y = year % 100;
    int w = (c / 4 - 2 * c + y + y / 4 + 13 * (month + 1) / 5 + day - 1) % 7;
    if (w < 0)
        w += 7;
    switch (w) {
        case 0:
            return "Sunday";
            break;
        case 1:
            return "Monday";
            break;
        case 2:
            return "Tuesday";
            break;
        case 3:
            return "Wednesday";
            break;
        case 4:
            return "Thursday";
            break;
        case 5:
            return "Friday";
            break;
        case 6:
            return "Saturday";
            break;
        default:
            return "";
            break;
    }
}
