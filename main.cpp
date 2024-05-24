#include <cmath>
#include <iostream>
#include <random>
#include <string>
#include <vector>
#include <cstring>
#include <cstdio>

using namespace std;

int[10] mtlc_ratios;

int[32] int_nums = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,20,21,23,24,25,26,28,29,30,32,34,37,39,41,42,45,48,49,52,56,60,64,66,69,74,77,79,84,91,97,104,106,111,119,125,128,137,147,58,169,172,181,194,203,208,223,238,239,256,274,280,294,315,28,338,362,386,388,416,446,453,478,512,532,549,588,625,630,676,724,734,776,832,862,891,955,1013,1024,1097,1176,1190,1261,1351,1398,1448,1552,1642,1663,1783,1911,1928,2048,2195,2265,2353,2521,2660,2702,2896,3104,3125};

for(int i = 0; i < 10; i++) {
  mtlc_ratios[i] = (ceil((2/(1+(sqrt(i+4))))*100)/100);
  cout << mtlc_ratios[i];
}

random_device rd;
mt19937 gen(rd());
uniform_real_distribution<> dis(0.0, 1.0);

int[] tonics = [1, 4, 5];
int[] dominants = [2, 8, 11, 12];
int[] predominants = [3, 6, 7, 9, 10];

int[3][][] chords = [
  [
    [1, 15, 17, 20], //Madd9 (a wind bell)
    [1, 8, 15, 20, 22, 24, 25], //M13 omit 3rd (black hole sun)
    [1, 8, 13, 17, 18, 20], //Madd11 (christian women)
    [1, 13, 25, 27, 28, 32, 37, 39, 40, 44, 49, 51, 52, 56], //madd9 (crazy hot)
    [1, 23, 25, 27, 28, 32, 35, 37, 39, 40, 42, 46, 48, 49, 51], // (funk for children)
    [1, 8, 11, 12, 13, 28, 30, 35], //madd#6Maj7sus11add#13 (idol)
    [1, 4, 9, 11, 16, 20, 21, 28], //m13 omit 9th omit 11th (intermezzio in a major)
    [1, 5, 6, 8, 13, 17, 20, 22], //Msus4sus13 (love of my life)
    [1, 13, 15, 17, 20, 25], //Madd9 (overjoyed)
    [1, 15, 16, 23], //m9 omit 5th (road taken)
    [], // ()
    [], // ()
    [], // ()
    [], // ()
    [], // ()
    [] // ()
  ],
  [ 
    [5, 18, 22, 25], //Mb13b9 omit 3rd, omit 5th, omit 7th (a wind bell)
    [1, 8, 15, 20, 22, 24, 25], //M13 omit 3rd (black hole sun)
    [1, 10, 15, 19, 20, 22], //M13#11 omit 3rd omit 7th (christian women)
    [1, 13, 29, 40, 41, 43, 49, 53, 54], //Madd11 (crazy hot)
    [1, 4, 5, 25, 27, 29, 30, 32, 36, 39, 41, 44, 46, 48, 49, 51], // (funk for children)
    [1, 4, 8, 13, 15, 22], //madd9addM13 (idol)
    [1, 4, 7, 10, 15, 16, 19, 22, 27], //dim9 (intermezzio in a major)
    [1, 11, 13, 15, 17, 23], //9 omit 5th (love of my life)
    [1, 17, 20, 25, 29, 30], //Msus11 (overjoyed)
    [1, 17, 23, 27], //#9 omit 5th (road taken)
    [], // ()
    [], // ()
    [], // ()
    [], // ()
    [], // ()
    [] // ()
  ],
  [  
    [11, 25, 28, 33], //11 omit 3rd, omit 5th (a wind bell)
    [1, 8, 15, 20, 22, 24, 25], //M13 omit 3rd (black hole sun)
    [1, 15, 20, 24, 25, 27], //M9 omit 3rd (christian women)
    [1, 13, 32, 43, 44, 46, 49, 51, 53, 55, 56], //M13#11 omit 7th (crazy hot)
    [1, 15, 18, 22, 23, 25, 29, 30, 32, 34, 35, 37, 39, 42, 45, 47], // (funk for children)
    [1, 8, 13, 20, 25, 27], //Madd9 (idol)
    [1, 13, 29, 33, 34, 44], //maddM13 (intermezzio in a major)
    [1, 8, 11, 13, 15, 16], //m9 (love of my life)
    [1, 13, 17, 24], //M7 omit 5th (overjoyed)
    [1, 8, 11, 17], //m7 (road taken)
    [], // ()
    [], // ()
    [], // ()
    [], // ()
    [], // ()
    [] // ()
  ]
];

string chords(ratio) {
  string[8][] chord_progression = new string[8][];
  for(int i = 0; i < chord_progression.length; i++) {
    if(rand() > ratio) {
      chord_progression[i] = chords[0][floor(rand()*chords.length)];
    } else if(rand() > ratio/2) {
      chord_progression[i] = chords[1][floor(rand()*chords.length)];
    } else {
      chord_progression[i] = chords[2][floor(rand()*chords.length)];
    }
  }
  return "";
}

typedef unsigned char byte;

/* First define a custom wrapper over std::vector<byte>
 * so we can quickly push_back multiple bytes with a single call.
 */
class MIDIvec: public std::vector<byte> {
public:
    // Methods for appending raw data into the vector:
    template<typename... Args>
    void AddBytes(byte data, Args...args) {
        push_back(data);
        AddBytes(args...);
    }
    template<typename... Args>
    void AddBytes(const char* s, Args...args) {
        insert(end(), s, s + std::strlen(s));
        AddBytes(args...);
    }
    void AddBytes() { }
};

/* Define a class which encodes MIDI events into a track */
class MIDItrack: public MIDIvec {
protected:
    unsigned delay, running_status;
public:
    MIDItrack()
        : MIDIvec(), delay(0), running_status(0) {
    }
    
    // Methods for indicating how much time elapses:
    void AddDelay(unsigned amount) { delay += amount; }
    
    void AddVarLen(unsigned t) {
        if(t >> 21) AddBytes(0x80 | ((t >> 21) & 0x7F));
        if(t >> 14) AddBytes(0x80 | ((t >> 14) & 0x7F));
        if(t >>  7) AddBytes(0x80 | ((t >>  7) & 0x7F));
        AddBytes(((t >> 0) & 0x7F));
    }
    
    void Flush() {
        AddVarLen(delay);
        delay = 0;
    }
    
    // Methods for appending events into the track:
    template<typename... Args>
    void AddEvent(byte data, Args...args) {
        /* MIDI tracks have the following structure:
         *
         * { timestamp [metaevent ... ] event } ...
         *
         * Each event is prefixed with a timestamp,
         * which is encoded in a variable-length format.
         * The timestamp describes the amount of time that
         * must be elapsed before this event can be handled.
         *
         * After the timestamp, comes the event data.
         * The first byte of the event always has the high bit on,
         * and the remaining bytes always have the high bit off.
         *
         * The first byte can however be omitted; in that case,
         * it is assumed that the first byte is the same as in
         * the previous command. This is called "running status".
         * The event may furthermore beprefixed
         * with a number of meta events.
         */
       Flush();
       if(data != running_status) AddBytes(running_status = data);
       AddBytes(args...);
    }
    void AddEvent() { }
    
    template<typename... Args>
    void AddMetaEvent(byte metatype, byte nbytes, Args...args) {
        Flush();
        AddBytes(0xFF, metatype, nbytes, args...);
    }
    
    // Key-related parameters: channel number, note number, pressure
    void KeyOn(int ch, int n, int p)    { if(n>=0)AddEvent(0x90|ch, n, p); }
    void KeyOff(int ch, int n, int p)   { if(n>=0)AddEvent(0x80|ch, n, p); }
    void KeyTouch(int ch, int n, int p) { if(n>=0)AddEvent(0xA0|ch, n, p); }
    // Events with other types of parameters:
    void Control(int ch, int c, int v) { AddEvent(0xB0|ch, c, v); }
    void Patch(int ch, int patchno)    { AddEvent(0xC0|ch, patchno); }
    void Wheel(int ch, unsigned value)
        { AddEvent(0xE0|ch, value&0x7F, (value>>7)&0x7F); }
    
    // Methods for appending metadata into the track:
    void AddText(int texttype, const char* text) {
        AddMetaEvent(texttype, std::strlen(text), text);
    }
};

/* Define a class that encapsulates all methods needed to craft a MIDI file. */
class MIDIfile: public MIDIvec {
protected:
    std::vector<MIDItrack> tracks;
    unsigned deltaticks, tempo;
public:
    MIDIfile()
        : MIDIvec(), tracks(), deltaticks(1000), tempo(1000000) {
    }
    
    void AddLoopStart()  { (*this)[0].AddText(6, "loopStart"); }
    void AddLoopEnd()    { (*this)[0].AddText(6, "loopEnd"); }
    
    MIDItrack& operator[] (unsigned trackno) {
        if(trackno >= tracks.size()) {
            tracks.reserve(16);
            tracks.resize(trackno+1);
        }
        
        MIDItrack& result = tracks[trackno];
        if(result.empty()) {
            // Meta 0x58 (misc settings):
                //      time signature: 4/2
                //      ticks/metro:    24
                //      32nd per 1/4:   8
            result.AddMetaEvent(0x58,4,  4,2, 24,8);
            // Meta 0x51 (tempo):
            result.AddMetaEvent(0x51,3,  tempo>>16, tempo>>8, tempo);
        }
        return result;
    }
    
    void Finish() {
        clear();
        AddBytes(
            // MIDI signature (MThd and number 6)
            "MThd", 0,0,0,6,
            // Format number (1: multiple tracks, synchronous)
            0,1,
            tracks.size() >> 8, tracks.size(),
            deltaticks    >> 8, deltaticks);
        for(unsigned a=0; a<tracks.size(); ++a) {
            // Add meta 0x2F to the track, indicating the track end:
            tracks[a].AddMetaEvent(0x2F, 0);
            // Add the track into the MIDI file:
            AddBytes("MTrk",
                tracks[a].size() >> 24,
                tracks[a].size() >> 16,
                tracks[a].size() >>  8,
                tracks[a].size() >>  0);
            insert(end(), tracks[a].begin(), tracks[a].end());
        }
    }
};

int main() {
    // Now that we have a class that can create MIDI files, let's create
    // music.
    
    // Begin with some chords.
    static const int chords[][3] = {
        { 12,4,7 }, // +C  E  G  = 0
        { 12,9,5 }, // +C  A  F  = 1
        { 12,8,3 }, // +C  G# D# = 2
        { 12,7,3 }, // +C  G  D# = 3
        { 12,5,8 }, // +C  F  G# = 4
        { 12,3,8 }, // +C  D# G# = 5
        { 11,2,7 }, //  B  D  G  = 6
        { 10,2,7 }, // A#  D  G  = 7
        { 14,7,5 }, // +D  G  F  = 8
        { 14,7,11 },// +D  G  B  = 9
        { 14,19,11 }// +D +G  B  = 10
    };
    const char x = 99; // Arbitrary value we use here to indicate "no note"
    static const char chordline[64] = {
        0,x,0,0,x,0,x, 1,x,1,x,1,1,x,1,x,  2,x,2,2,x,2,x, 3,x,3,x,3,3,x,3,x,
        4,x,4,4,x,4,x, 5,x,5,x,5,5,x,5,x,  6,7,6,x,8,x,9,x,10,x,x,x,x,x,x,x
    };
    static const char chordline2[64] = {
        0,x,x,x,x,x,x, 1,x,x,x,x,x,x,x,x,  2,x,x,x,x,x,x, 3,x,x,x,x,x,x,x,x,
        4,x,x,x,x,x,x, 5,x,x,x,x,x,x,x,x,  6,x,x,x,x,x,x,x, 6,x,x,x,x,x,x,x
    };
    static const char bassline[64] = {
        0,x,x,x,x,x,x, 5,x,x,x,x,x,x,x,x,  8,x,x,0,x,3,x, 7,x,x,x,x,x,x,x,x,
        5,x,x,x,x,x,x, 3,x,x,x,x,x,x,x,x,  2,x,x,x,x,x,x,-5,x,x,x,x,x,x,x,x
    };
    static const char fluteline[64] = {
        12,x,12,12, x,9, x, 17,x,16,x,14,x,12,x,x,
         8,x, x,15,14,x,12,  x,7, x,x, x,x, x,x,x,
         8,x, x, 8,12,x, 8,  x,7, x,8, x,3, x,x,x,
         5,x, 7, x, 2,x,-5,  x,5, x,x, x,x, x,x,x
    };
    
    MIDIfile file;
    file.AddLoopStart();
    
    /* Choose instruments ("patches") for each channel: */
    static const char patches[16] = {
        0,0,0, 52,52,52, 48,48,48, 0,0,0,0,0, 35,74
        /* 0=piano, 52=choir aahs, 48=strings, 35=fretless bass, 74=pan flute */
    };
    for(unsigned c=0; c<16; ++c)
        if(c != 10) // Patch any other channel but not the percussion channel.
            file[0].Patch(c, patches[c]);
    
    int keys_on[16] = {-1,-1,-1,-1, -1,-1,-1,-1, -1,-1,-1,-1, -1,-1,-1,-1 };
    for(unsigned loops=0; loops<2; ++loops) {
        for(unsigned row=0; row<128; ++row) {
            for(unsigned c=0; c<16; ++c) {
                int note = x, add = 0, vol = 127;
                if(c < 3) // Piano chord { 
                    int chord = chordline[row%64];
                    if(chord != x) 
                        note = chords[chord][c%3], add=12*5, vol=0x4B; 
                    } else if(c >= 3 && c < 5) // Aux chord (choir) { 
                        int chord = chordline2[row%64];
                        if(chord != x) 
                            note = chords[chord][c%3], add=12*4, vol=0x50; 
                        } else if(c >= 6 && c < 8) // Aux chord (strings) { 
                            int chord = chordline2[row%64];
                            if(chord != x) 
                                note = chords[chord][c%3], add=12*5, vol=0x45;
                            } else if(c == 14) // Bass
                                note = bassline[row%64], add=12*3, vol=0x6F;
                            else if(c == 15 && row >= 64) // Flute
                                note = fluteline[row%64], add=12*5, vol=0x6F;
                                if(note == x && (c<15 || row%31)) 
                                    continue;
                file[0].KeyOff(c, keys_on[c], 0x20);
                keys_on[c] = -1;
                if(note == x) continue;
                file[0].KeyOn(c, keys_on[c] = note+add, vol);
            }
            file[0].AddDelay(160);
        }
        if(loops == 0) file.AddLoopEnd();
    }
    
    file.Finish();
    
    FILE* fp = std::fopen("test.mid", "wb");
    std::fwrite(&file.at(0), 1, file.size(), fp);
    std::fclose(fp);
    
    return 0;
}
