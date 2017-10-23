#include <iostream>
#include <array>

using namespace std;

class Service
{
public:
	Service() {};
	virtual string ServiceName() = 0;
	/* virtual string GetProvider() = 0;
	virtual void SetProvider(string p) = 0;*/
	virtual bool UseKeyboard() = 0;
	virtual void Can() = 0;
protected:
	string Provider;
};

class Phone : public Service
{
public:
	Phone() {};
	void PlaceCall(int n)
	{
		cout << "Calling " << n << "..." << endl;
	}

	void ReceiveCall()
	{
		cout << "Receiving call..." << endl;
	}

	void SetVolume(int v)
	{
		if (v > 0 && v < 11)
		{
			this->Volume = v;
		}
	}

	void DeclineCall()
	{
		cout << "Declining call..." << endl;
	}

	string Phone::ServiceName()
	{
		return "Phone";
	}

	void Phone::Can()
	{
		cout << "Receive and place call. Also change the device volume" << endl;
	}

	bool UseKeyboard()
	{
		return true;
	}

protected:
	int Volume;

};

class Camera : public Service
{
public:
	Camera() {}

	void Save()
	{
		cout << "Photo saved!" << endl;
	}

	void Load() {}

	string ServiceName()
	{
		return "Camera";
	}

	void Camera::Can()
	{
		cout << "Take and save picutres." << endl;
	}

	bool UseKeyboard()
	{
		return false;
	}

};

class VideoCamera : public Camera
{
public:

	VideoCamera() {}

	void Record() {}

	void StopRecording() {}

	string ServiceName()
	{
		return "Video Camera";
	}

	void Can()
	{
		cout << "Record videos." << endl;
	}

	bool UseKeyboard()
	{
		return false;
	}
};

class PictureCamera : public Camera
{
public:
	PictureCamera() {}

	string ServiceName()
	{
		return "Picture Camera";
	}

	void TakePicture() {}

	void Can()
	{
		cout << "Take and save picutres." << endl;
	}

	bool UseKeyboard()
	{
		return false;
	}
};

class Player : public Service
{
public:
	Player() {}

	void Play() {}

	void StopPlaying() {}

	string ServiceName()
	{
		return "Player";
	}

	void Can()
	{
		cout << "Play music." << endl;
	}

	bool UseKeyboard()
	{
		return false;
	}
};

class Mp3Player : public Player
{
public:
	Mp3Player() {}

	void Play(string s)
	{
		this->Mp3File = s;
		cout << "Playing music " << endl;
	}

	string GetMp3FileName()
	{
		return this->Mp3File;
	}

	string ServiceName()
	{
		return "Mp3Player";
	}

	void Can()
	{
		cout << "Play music." << endl;
	}

	bool UseKeyboard()
	{
		return false;
	}

protected:
	string Mp3File;
};

class VideoPlayer : public Player
{
public:
	VideoPlayer() {}

	void Play(string v)
	{
		this->VideoFile = v;
		cout << "Playing video..." << endl;
	}

	string GetVideoFile()
	{
		return this->VideoFile;
	}

	string ServiceName()
	{
		return "Video Player";
	}

	void Can()
	{
		cout << "Play video." << endl;
	}

	bool UseKeyboard()
	{
		return false;
	}

protected:
	string VideoFile;
};

class Messaging : public Service
{
public:
	Messaging() {}

	void Send(string m)
	{
		cout << "Message sended!" << endl;
	}

	void Receive()
	{
		cout << "New message received" << endl;
	}

	string ServiceName()
	{
		return "Messaging";
	}

	void Can()
	{
		cout << "Send and receive messages." << endl;
	}

	bool UseKeyboard()
	{
		return true;
	}
};

class SmallMessaging : public Messaging
{
public:
	SmallMessaging() {}
	string ServiceName()
	{
		return "SMS";
	}


protected:
	string Text;
};

class MultimediaMessaging : public Messaging
{
public:
	MultimediaMessaging() {}

	string ServiceName()
	{
		return "MMS";
	}


protected:
	string MMSFilename;
};

class GameConsole : public Service
{
public:
	GameConsole() {}
	void Play() {}

	void StopPlaying() {}

	void SaveGame() {}

	void LoadGame() {}

	string ServiceName()
	{
		return "Games";
	}

	void Can()
	{
		cout << "Play games." << endl;
	}

	bool UseKeyboard()
	{
		return true;
	}
};

class WebBrowser : public Service
{
public:
	WebBrowser() {}
	void Go(string URL) {}

	void Cache() {}

	void OpenNewTab() {}

	string ServiceName()
	{
		return "HTTPCLient";
	}

	void Can()
	{
		cout << "Web borwsing." << endl;
	}

	bool UseKeyboard()
	{
		return true;
	}

};

class DayPlanner : public Service
{
public:
	DayPlanner() {}
	void AddEntry() {}

	void ModifyEntry() {}

	void DeleteEntrey() {}

	void Can()
	{
		cout << "Planning your day." << endl;
	}

	bool UseKeyboard()
	{
		return true;
	}

	string ServiceName()
	{
		return "Planner";
	}

};

class EmailClient : public Service
{
public:
	EmailClient() {}

	void Send() {}

	void Receive() {}

	void Reply() {}

	void Forward() {}

	void Can()
	{
		cout << "Send and receive emails." << endl;
	}

	bool UseKeyboard()
	{
		return true;
	}

	string ServiceName()
	{
		return "Planner";
	}
};

class Gmail : public EmailClient
{
public:
	Gmail() {}

	string ServiceName()
	{
		return "Gmail";
	}

protected:
	string SMTP, POP, IMAP;

};

class Yahoo : public EmailClient
{
public:
	Yahoo() {}
	string ServiceName()
	{
		return "Yahoo";
	}

protected:
	string SMTP, POP, IMAP;

};



void main()
{
	Phone _phone;
	Camera _camera;
	VideoCamera _videoCamera;
	PictureCamera _pictureCamera;
	Player _player;
	Mp3Player _mp3Player;
	VideoPlayer _videoPlayer;
	Messaging _messaging;
	SmallMessaging _smallMessaging;
	MultimediaMessaging _multimediaMessaging;
	GameConsole _gameConsole;
	WebBrowser _webBrowser;
	DayPlanner _dayPlanner;
	EmailClient _emailClient;
	Gmail _gmail;
	Yahoo _yahoo;


	std::array< Service*, 16> ServiceList{
		&_phone, &_camera, &_videoCamera, &_pictureCamera, &_player, &_mp3Player, &_videoPlayer, &_messaging, &_smallMessaging,
		&_multimediaMessaging, &_gameConsole, &_webBrowser, &_dayPlanner, &_emailClient, &_gmail, &_yahoo

	};

	for (unsigned int i = 0; i < ServiceList.size(); i++)
	{
		cout << "Service: ";
		printf("%s\n", ServiceList[i]->ServiceName().c_str());
		//cout << ServiceList[i]->ServiceName();
		cout << "Can do: ";
		ServiceList[i]->Can();
		cout << "Use keyboard: " << (ServiceList[i]->UseKeyboard() ? "Yes" : "No") << endl << endl;
		
	}
		

	system("pause");
	//const std::array<const Service, 3> ServiceList = { Phone(), Camera(), VideCamera() };
}