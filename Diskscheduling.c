#include &lt;stdio.h&gt;
#include &lt;stdlib.h&gt;
#include &lt;stdbool.h&gt;
#include &lt;limits.h&gt;
void shortestSeekTimeFirst(int request[], int head, int n)
{
    int seek_sequence[n];
    int seek_count = 0;
    bool visited[n];
    for (int i = 0; i &lt; n; i++)
    {
        visited[i] = false;
    }
    for (int i = 0; i &lt; n; i++)
    {
        int min_distance = INT_MAX;
        int index = -1;
        for (int j = 0; j &lt; n; j++)
        {
            if (!visited[j] &amp;&amp; abs(head - request[j]) &lt; min_distance)
            {
                index = j;
                min_distance = abs(head - request[j]);
            }
        }
        visited[index] = true;
        seek_sequence[i] = request[index];
        seek_count += min_distance;
        head = request[index];
    }
    printf(&quot;SSTF Disk Scheduling Algorithm:\n&quot;);
    printf(&quot;Total seek time: %d\n&quot;, seek_count);
    printf(&quot;Seek sequence: &quot;);
    for (int i = 0; i &lt; n; i++)
    {
        printf(&quot;%d &quot;, seek_sequence[i]);
    }
    printf(&quot;\n\n&quot;);
}
void scan(int request[], int head, int n, int direction, int disk_size)
{

    int seek_sequence[n + 1];
    int seek_count = 0;
    int distance;
    int cur_track;
    for (int i = 0; i &lt; n; i++)
    {
        for (int j = i + 1; j &lt; n; j++)
        {
            if (request[i] &gt; request[j])
            {
                int temp = request[i];
                request[i] = request[j];
                request[j] = temp;
            }
        }
    }
    int index;
    for (index = 0; index &lt; n; index++)
    {
        if (head &lt; request[index])
        {
            break;
        }
    }
    int left = index - 1;
    int right = index;
    int seek_sequence_index = 0;
    // Handle right direction
    if(direction==1)
    {
        while (right &lt; n)
        {
            cur_track = request[right];
            distance = abs(cur_track - head);
            seek_count += distance;
            seek_sequence[seek_sequence_index++] = cur_track;
            head = cur_track;
            right++;
        }
        cur_track = disk_size-1;
        distance = abs(cur_track - head);
        seek_count += distance;

        seek_sequence[seek_sequence_index++] = cur_track;
        head = cur_track;
        while (left &gt;= 0)
        {
            cur_track = request[left];
            distance = abs(cur_track - head);
            seek_count += distance;
            seek_sequence[seek_sequence_index++] = cur_track;
            head = cur_track;
            left--;
        }
    }
    else if(direction==0)
    {
        while (left &gt;= 0)
        {
            cur_track = request[left];
            distance = abs(cur_track - head);
            seek_count += distance;
            seek_sequence[seek_sequence_index++] = cur_track;
            head = cur_track;
            left--;
        }
        cur_track = 0;
        distance = abs(cur_track - head);
        seek_count += distance;
        seek_sequence[seek_sequence_index++] = cur_track;
        head = cur_track;
        while (right &lt; n)
        {
            cur_track = request[right];
            distance = abs(cur_track - head);
            seek_count += distance;
            seek_sequence[seek_sequence_index++] = cur_track;
            head = cur_track;
            right++;
        }
    }
    printf(&quot;SCAN Disk Scheduling Algorithm:\n&quot;);
    printf(&quot;Total seek time: %d\n&quot;, seek_count);
    printf(&quot;Seek sequence: &quot;);
    for (int i = 0; i &lt;= n; i++)
    {
        printf(&quot;%d &quot;, seek_sequence[i]);

    }
    printf(&quot;\n\n&quot;);
}
void cLook(int request[], int head, int n, int direction, int disk_size)
{
    int seek_sequence[n];
    int seek_count = 0;
    int distance;
    int cur_track;
    for (int i = 0; i &lt; n - 1; i++)
    {
        for (int j = i + 1; j &lt; n; j++)
        {
            if (request[i] &gt; request[j])
            {
                int temp = request[i];
                request[i] = request[j];
                request[j] = temp;
            }
        }
    }
    int index;
    for (index = 0; index &lt; n; index++)
    {
        if (head &lt; request[index])
        {
            break;
        }
    }
    int left = index-1;
    int right = index;
    for (int i = 0; i &lt; n; i++)
    {
        if (direction == 0)
        {
            if (left &lt;= 0)
            {
                cur_track = request[0];
                left = n-1;
            }
            else
            {
                cur_track = request[left];

                left--;
            }
        }
        else if(direction == 1)
        {
            cur_track = request[right];
            right = (right + 1) % n;
        }
        distance = abs(cur_track - head);
        seek_sequence[i] = cur_track;
        head = cur_track;
        seek_count += distance;
    }
    printf(&quot;C-LOOK Disk Scheduling Algorithm:\n&quot;);
    printf(&quot;Total seek time: %d\n&quot;, seek_count);
    printf(&quot;Seek sequence: &quot;);
    for (int i = 0; i &lt; n; i++)
    {
        printf(&quot;%d &quot;, seek_sequence[i]);
    }
    printf(&quot;\n\n&quot;);
}
int main()
{
    int n, head, direction;
    int disk_size = 200;
    printf(&quot;Enter the number of requests: &quot;);
    scanf(&quot;%d&quot;, &amp;n);
    printf(&quot;Enter the Disk Size : &quot;);
    scanf(&quot;%d&quot;,&amp;disk_size);
    int proc[n];
    printf(&quot;Enter the requests: &quot;);
    for(int i = 0; i &lt; n; i++)
    {
        scanf(&quot;%d&quot;, &amp;proc[i]);
    }
    printf(&quot;Enter the initial head position: &quot;);
    scanf(&quot;%d&quot;, &amp;head);
    printf(&quot;Enter the direction (0 for left, 1 for right): &quot;);
    scanf(&quot;%d&quot;, &amp;direction);
    for (int i = 0; i &lt; n - 1; i++)
    {
        for (int j = i + 1; j &lt; n; j++)
        {
            if (proc[i] &gt; proc[j])

            {
                int temp = proc[i];
                proc[i] = proc[j];
                proc[j] = temp;
            }
        }
    }
    shortestSeekTimeFirst(proc, head, n);
    scan(proc, head, n, direction, disk_size);
    cLook(proc, head, n, direction, disk_size);
    return 0;
}

OUTPUT &gt;&gt;
Enter the number of requests: 7
Enter the Disk Size : 200
Enter the requests: 82
170
43
140
24
16
190
Enter the initial head position: 50
Enter the direction (0 for left, 1 for right): 1
SSTF Disk Scheduling Algorithm:
Total seek time: 208
Seek sequence: 43 24 16 82 140 170 190
SCAN Disk Scheduling Algorithm:
Total seek time: 332
Seek sequence: 82 140 170 190 199 43 24 16
C-LOOK Disk Scheduling Algorithm:
Total seek time: 341
Seek sequence: 82 140 170 190 16 24 43