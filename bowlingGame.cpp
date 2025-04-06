#include <iostream>
#include <cstring>
using namespace std;

typedef enum _bonusType
{
    NONE,
    SPARE,
    STRIKE
} BonusType;

class Frame
{
    int frameNum;
    bool isBonusReceivedInThisFrame; 
    bool isFramePresent;
    int noOfPinsKnockedDownTry[3];
    int frameScore;
    int previousFrameScore;
    bool isFrameScoreCalculated;
    BonusType bonusType;

    public:
    
    Frame();
    void calculateFrameScore(Frame &frame1, Frame &frame2);
    void setFrameNum(int frameNumVal);
    void setIsBonusReceivedInThisFrame(bool isBonusReceivedInThisFrameVal);
    void setIsFramePresent(bool isFramePresentVal);
    void setBonusType(BonusType bonusTypeVal);
    void setNoOfPinsKnockedDownTry(int noOfPinsKnockedDownTry, int idx);
    int getNoOfPinsKnockedDownTry(int idx);
};

class BowlingGame
{
    int f;
    int r;
    int c;
    Frame frames[10];
    int roll[3];

    public:
    BowlingGame();
    void start(void);
};

Frame::Frame()
{
    memset(&noOfPinsKnockedDownTry, 0, sizeof(noOfPinsKnockedDownTry));

    frameScore = 0;
    previousFrameScore = 0;
    isBonusReceivedInThisFrame = false;
    isFrameScoreCalculated = false;
    isFramePresent = false;
    bonusType = NONE;
}

void Frame::calculateFrameScore(Frame &frame1, Frame &frame2)
{
    if (isFrameScoreCalculated == true)
    {
        frame1.previousFrameScore = frameScore;
        return;
    }

    if (isBonusReceivedInThisFrame == true && bonusType == SPARE)
    {
        if (frame1.isFramePresent && frame1.isBonusReceivedInThisFrame == false && frame1.bonusType == NONE)
        {
            frameScore = previousFrameScore + noOfPinsKnockedDownTry[0] + noOfPinsKnockedDownTry[1] + frame1.noOfPinsKnockedDownTry[0];
            cout << "****           frameScore["<<frameNum<<"] : " << frameScore << "  ****" << endl;
            frame1.previousFrameScore = frameScore;
            isFrameScoreCalculated = true;
        }
        else if (frame1.isFramePresent && frame1.isBonusReceivedInThisFrame == true && frame1.bonusType == SPARE)
        {
            frameScore = previousFrameScore + noOfPinsKnockedDownTry[0] + noOfPinsKnockedDownTry[1] + frame1.noOfPinsKnockedDownTry[0];
            cout << "****           frameScore["<<frameNum<<"] : " << frameScore << "  ****" << endl;
            frame1.previousFrameScore = frameScore;
            isFrameScoreCalculated = true;
        }
        else if (frame1.isFramePresent && frame1.isBonusReceivedInThisFrame == true && frame1.bonusType == STRIKE)
        {
            frameScore = previousFrameScore + noOfPinsKnockedDownTry[0] + noOfPinsKnockedDownTry[1] + frame1.noOfPinsKnockedDownTry[0];
            cout << "****           frameScore["<<frameNum<<"] : " << frameScore << "  ****" << endl;
            frame1.previousFrameScore = frameScore;
            isFrameScoreCalculated = true;
        }
    }
    else if (isBonusReceivedInThisFrame == true && bonusType == STRIKE)
    {
        if (frame1.isFramePresent && frame1.isBonusReceivedInThisFrame == false && frame1.bonusType == NONE)
        {
            frameScore = previousFrameScore + noOfPinsKnockedDownTry[0] + frame1.noOfPinsKnockedDownTry[0] + frame1.noOfPinsKnockedDownTry[1];
            cout << "****           frameScore["<<frameNum<<"] : " << frameScore << "  ****" << endl;
            frame1.previousFrameScore = frameScore;
            isFrameScoreCalculated = true;
        }
        else if (frame1.isFramePresent && frame1.isBonusReceivedInThisFrame == true && frame1.bonusType == SPARE)
        {
            frameScore = previousFrameScore + noOfPinsKnockedDownTry[0] + frame1.noOfPinsKnockedDownTry[0] + frame1.noOfPinsKnockedDownTry[1];
            cout << "****           frameScore["<<frameNum<<"] : " << frameScore << "  ****" << endl;
            frame1.previousFrameScore = frameScore;
            isFrameScoreCalculated = true;
        }
        else if (frame1.isFramePresent && frame1.isBonusReceivedInThisFrame == true && frame1.bonusType == STRIKE)
        {
            if (frame2.isFramePresent && frame2.isBonusReceivedInThisFrame == false && frame2.bonusType == NONE)
            {
                frameScore = previousFrameScore + noOfPinsKnockedDownTry[0] + frame1.noOfPinsKnockedDownTry[0] + frame2.noOfPinsKnockedDownTry[0];
                cout << "****           frameScore["<<frameNum<<"] : " << frameScore << "  ****" << endl;
                frame1.previousFrameScore = frameScore;
                isFrameScoreCalculated = true;
            }  
            else if (frame2.isFramePresent && (frame2.isBonusReceivedInThisFrame == true) && (frame2.bonusType == SPARE || frame2.bonusType == STRIKE))
            {
                frameScore = previousFrameScore + noOfPinsKnockedDownTry[0] + frame1.noOfPinsKnockedDownTry[0] + frame2.noOfPinsKnockedDownTry[0];
                cout << "****           frameScore["<<frameNum<<"] : " << frameScore << "  ****" << endl;
                frame1.previousFrameScore = frameScore;
                isFrameScoreCalculated = true;
            }           
        }
    }
    else
    {
        frameScore = previousFrameScore + noOfPinsKnockedDownTry[0] + noOfPinsKnockedDownTry[1] + noOfPinsKnockedDownTry[2];
        cout << "****           frameScore["<<frameNum<<"] : " << frameScore << "  ****" << endl;
        isFrameScoreCalculated = true;
    }
}

void Frame::setFrameNum(int frameNumVal)
{
    frameNum = frameNumVal;
}

void Frame::setIsBonusReceivedInThisFrame(bool isBonusReceivedInThisFrameVal)
{
    isBonusReceivedInThisFrame = isBonusReceivedInThisFrameVal;
}

void Frame::setIsFramePresent(bool isFramePresentVal)
{
    isFramePresent = isFramePresentVal;
}

void Frame::setBonusType(BonusType bonusTypeVal)
{
    bonusType = bonusTypeVal;
}

void Frame::setNoOfPinsKnockedDownTry(int noOfPinsKnockedDownTryVal, int idx)
{
    noOfPinsKnockedDownTry[idx] = noOfPinsKnockedDownTryVal;
}

int Frame::getNoOfPinsKnockedDownTry(int idx)
{
    return noOfPinsKnockedDownTry[idx];
}


BowlingGame::BowlingGame()
{
    f = 0; r = 0; c = 0;
    memset(&roll, 0, sizeof(roll));
}

void BowlingGame::start(void)
{
    int noOfPinsKnockedDown = 0; 
    for (f = 0; f < 10; f++)
    {
        for (r = 0; r < 3; r++)
        {
            noOfPinsKnockedDown = 0;

            frames[f].setFrameNum((f+1));
            frames[f].setIsFramePresent(true);

            if(r == 0)
            {
                cout << "Frame: " << (f+1) << " , Try num: " << r << "  ";
                cin >> noOfPinsKnockedDown;
    
                if (noOfPinsKnockedDown > 10 || noOfPinsKnockedDown < 0)
                {
                    cout << "Invalid value entered for noOfPinsKnockedDown, exiting.." << endl;
                    return;
                }
                
                frames[f].setNoOfPinsKnockedDownTry(noOfPinsKnockedDown, r);
                  
                if ((f != 9) && frames[f].getNoOfPinsKnockedDownTry(r) == 10)
                {
                    frames[f].setIsBonusReceivedInThisFrame(true);
                    frames[f].setBonusType(STRIKE);
                    break;
                }
            }
            else if(r == 1)
            {
                cout << "Frame: " << (f+1) << " , Try num: " << r << "  ";
                cin >> noOfPinsKnockedDown;
    
                if (noOfPinsKnockedDown > 10 || noOfPinsKnockedDown < 0)
                {
                    cout << "Invalid value entered for noOfPinsKnockedDown, exiting.." << endl;
                    return;
                }
                
                frames[f].setNoOfPinsKnockedDownTry(noOfPinsKnockedDown, r);
                
                if ((f != 9) && (frames[f].getNoOfPinsKnockedDownTry((r-1)) + frames[f].getNoOfPinsKnockedDownTry(r)) == 10)
                {
                    frames[f].setIsBonusReceivedInThisFrame(true);
                    frames[f].setBonusType(SPARE);
                    break;
                }
            }
            else if (f == 9 && r == 2)
            {
                cout << "Frame: " << (f+1) << " , Try num: " << r << "  ";
                cin >> noOfPinsKnockedDown;
    
                if (noOfPinsKnockedDown > 10 || noOfPinsKnockedDown < 0)
                {
                    cout << "Invalid value entered for noOfPinsKnockedDown, exiting.." << endl;
                    return;
                }
                
                frames[f].setNoOfPinsKnockedDownTry(noOfPinsKnockedDown, r);
            }
        }

        for (c = ((f <=2) ? 0 : (f-2)); c <= f; c++)
        {
            frames[c].calculateFrameScore(frames[c+1], frames[c+2]);
        }
    }
}

/*
 * Program calculating the score of a single player in Bowling
 * Implemented by Vikash Madnawat
 */
int main()
{
    BowlingGame bowlingGame;

    bowlingGame.start();

    cout << "Bowling Game over." << endl;
    return 0;
}
