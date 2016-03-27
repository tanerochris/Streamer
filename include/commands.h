
/*defines the various commands Macro available*/
#include<string>
#define ADDTRACK 0
#define PLAYTRACK 1
#define DELETETRACK 2
#define LISTTRACK 3
#define SEARCH 4
#define DOWNLOAD 5
using namespace std;
//function definition of commands
class Track{
public:
 string  trackTitle;
 string  trackSize;
 string  trackLength;
 string  trackLink;
 int     trackId;
  Track();
  int addTrack();
  int playTrack();
  int deleteTrack();
  int deleteTrack(int TrackId);
  int deleteTrack(string TrackName);
  int searchTrack(string trackName);
  int downloadTrack(int trackID);

};

void command(string const commandLine);

