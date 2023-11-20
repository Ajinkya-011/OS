#include&lt;stdio.h&gt;
#include&lt;stdlib.h&gt;
void printFrames(int frames[], int frameSize) {
    for (int i = 0; i &lt; frameSize; ++i) {
        if (frames[i] == -1) {
            printf(&quot;X &quot;);
        } else {
            printf(&quot;%d &quot;, frames[i]);
        }
    }
    printf(&quot;\n&quot;);
}
void FCFS(int pages[], int frameSize, int n) {
    int frames[frameSize];
    int counter = 0;
    int pageFaults = 0;
    for (int i = 0; i &lt; frameSize; ++i) {
        frames[i] = -1;
    }
    for (int i = 0; i &lt; n; ++i) {
        int pageExists = 0;
        for (int j = 0; j &lt; frameSize; ++j) {
            if (frames[j] == pages[i]) {
                pageExists = 1;
                break;
            }
        }
    if (pageExists == 0) {
        frames[counter] = pages[i];
        ++counter;
        ++pageFaults;
        if (counter &gt;= frameSize) {
            counter = 0;

        }
    }
    printf(&quot;Frames (FCFS): &quot;);
    printFrames(frames, frameSize);
    }
    printf(&quot;Number of page faults using FCFS: %d\n\n&quot;, pageFaults);
}
void LRU(int pages[], int frameSize, int n) {
    int frames[frameSize];
    int counter = 0;
    int pageFaults = 0;
    int recent[frameSize] = {-1, -1, -1};
    for (int i = 0; i &lt; frameSize; ++i) {
        frames[i] = -1;
    }
    for (int i = 0; i &lt; n; ++i) {
        int pageExists = 0;
    for (int j = 0; j &lt; frameSize; ++j) {
        if (frames[j] == pages[i]) {
            pageExists = 1;
            recent[j] = i;
            break;
        }
    }
    if (pageExists == 0) {
        int leastRecentIndex = 0;
        for (int j = 1; j &lt; frameSize; ++j) {
            if (recent[j] &lt; recent[leastRecentIndex]) {
                leastRecentIndex = j;
            }
        }
        frames[leastRecentIndex] = pages[i];
        recent[leastRecentIndex] = i;
        ++pageFaults;
    }

    printf(&quot;Frames (LRU): &quot;);
    printFrames(frames, frameSize);
    }
    printf(&quot;Number of page faults using LRU: %d\n\n&quot;, pageFaults);
}
void Optimal(int pages[], int frameSize,int n) {
    int frames[frameSize];
    int pageFaults = 0;
    for (int i = 0; i &lt; frameSize; ++i) {
        frames[i] = -1;
    }
    for (int i = 0; i &lt; n; ++i) {
        int pageExists = 0;
    for (int j = 0; j &lt; frameSize; ++j) {
        if (frames[j] == pages[i]) {
            pageExists = 1;
            break;
        }
    }
    if (pageExists == 0) {
        int maxDistance = -1;
        int replaceIndex = -1;
        for (int j = 0; j &lt; frameSize; ++j) {
            int futureIndex = 0;
            for (int k = i + 1; k &lt; 20; ++k) {
                if (frames[j] == pages[k]) {
                    futureIndex = k;
                    break;
            }
            }
            if (futureIndex == 0) {
                replaceIndex = j;
                break;
            } else {
                if (futureIndex &gt; maxDistance) {

                    maxDistance = futureIndex;
                    replaceIndex = j;
                }
            }
        }
        frames[replaceIndex] = pages[i];
        ++pageFaults;
    }
    printf(&quot;Frames (Optimal): &quot;);
    printFrames(frames, frameSize);
    }
    printf(&quot;Number of page faults using Optimal: %d\n\n&quot;, pageFaults);
}
int main() {
    int pages[20];
    int n;
    printf(&quot;Enter the size of string \n&quot;);
    scanf(&quot;%d&quot;,&amp;n);
    printf(&quot;Enter the reference string:\n&quot;);
    for (int i = 0; i &lt; n; ++i) {
        scanf(&quot;%d&quot;, &amp;pages[i]);
    }
    int frameSize = 3;
    FCFS(pages, frameSize,n);
    LRU(pages, frameSize,n);
    Optimal(pages, frameSize,n);
    return 0;
}