int maxMeetings(int start[], int end[], int n)
{
    // Approach is to end the mee first wich ends first

    // Make a Pair with end time as its first value.
    // sort them according to end time.

    vector<pair<int, int>> meetings;
    for (int i = 0; i < n; i++)
    {
        meetings.push_back({end[i], start[i]});
    }
    sort(meetings.begin(), meetings.end());

    int totalMeetings = 1;

    // for comparing the last meeting end and next meeting starting
    int lastEnd = meetings[0].first;

    for (int i = 1; i < n; i++)
    {
        if (meetings[i].second > lastEnd)
        {
            totalMeetings++;

            lastEnd = meetings[i].first;
        }
    }

    return totalMeetings;
}