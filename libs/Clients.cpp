
// For compilers that support precompilation, includes "wx/wx.h".
#include <wx/wxprec.h>
#include <wx/socket.h>
#include <string>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif
using namespace std;
class StreamerClient: public wxApp
{
	public:

	virtual bool OnInit();
};
class StreamerFrame: public wxFrame
{
	public:
		wxSockAddress *ip;
		StreamerFrame(const wxString& title, const wxPoint& pos, const wxSize& size);
	private:
		void OnConnectDisconnect(wxCommandEvent& event);
		void OnDisConnect(wxCommandEvent& event);
		void OnPlay(wxCommandEvent& event);
		void OnStop(wxCommandEvent& event);
		void OnPause(wxCommandEvent& event);
		void OnAddTrack(wxCommandEvent& event);
		void OnDelTrack(wxCommandEvent& event);
		void OnShareTrack(wxCommandEvent& event);
		void OnExit(wxCommandEvent& event);
		void OnAbout(wxCommandEvent& event);
		void OnConnectionEstablished(wxSocketEvent& event);
		void OnConnectionLost(wxSocketEvent& event);
		wxButton *connect;
		wxButton *play;
		wxButton *stop; 
		wxButton *pause;
		wxButton *addTrack;
		wxButton *delTrack;
		wxButton *shareTrack;
		wxSocketClient *client;
		wxDECLARE_EVENT_TABLE();
};
enum
{
 CONNECT_DISCONNECT = 1,PLAY,STOP,PAUSE,ADDTRACK,DELTRACK,SHARETRACK
};
wxBEGIN_EVENT_TABLE(StreamerFrame, wxFrame)
EVT_BUTTON(CONNECT_DISCONNECT, StreamerFrame::OnConnectDisconnect)
EVT_BUTTON(PLAY, StreamerFrame::OnPlay)
EVT_BUTTON(STOP, StreamerFrame::OnStop)
EVT_BUTTON(PAUSE, StreamerFrame::OnPause)
EVT_BUTTON(ADDTRACK, StreamerFrame::OnAddTrack)
EVT_BUTTON(DELTRACK, StreamerFrame::OnDelTrack)
EVT_BUTTON(SHARETRACK, StreamerFrame::OnShareTrack)
EVT_MENU(wxID_EXIT, StreamerFrame::OnExit)
EVT_MENU(wxID_ABOUT, StreamerFrame::OnAbout)
EVT_SOCKET(wxSOCKET_CONNECTION,StreamerFrame::OnConnectionEstablished)
EVT_SOCKET(wxSOCKET_LOST,StreamerFrame::OnConnectionLost)

wxEND_EVENT_TABLE()
wxIMPLEMENT_APP(StreamerClient);

bool StreamerClient::OnInit()
{
StreamerFrame *frame = new StreamerFrame( "Streamer", wxPoint(200, 400), wxSize(600, 600) );

frame->Show( true );
//setTopWindow(frame);

return true;
};

StreamerFrame::StreamerFrame(const wxString& title, const wxPoint& pos, const wxSize& size)
: wxFrame(NULL, wxID_ANY, title, pos, size)
{     ip = new wxSockAddress();
	ip->Hostname("127.0.0.1");
	
	//we create the various btns
    connect  = new wxToggleButton(this, CONNECT_DISCONNECT, _T("connect"),wxPoint(5, 20), wxDefaultSize, 0);
		play  = new wxButton(this, PLAY, _T("play"),wxPoint(5, 40), wxDefaultSize, 0);
	   stop  = new wxButton(this, STOP, _T("stop"),wxPoint(5, 70), wxDefaultSize, 0);
 	   pause  = new wxButton(this, PAUSE, _T("pause"),wxPoint(5, 110), wxDefaultSize, 0);
 	   addTrack = new wxButton(this, ADDTRACK, _T("Add track"),wxPoint(5, 140), wxDefaultSize, 0);
	delTrack = new wxButton(this, DELTRACK, _T("Delete Track"),wxPoint(5, 170), wxDefaultSize, 0);
	shareTrack = new wxButton(this, SHARETRACK, _T("share"),wxPoint(5, 200), wxDefaultSize, 0);
    CreateStatusBar();
SetStatusText( "Welcome to Streamer" );
}
void StreamerFrame::OnConnectDisconnect(wxCommandEvent& event){
	  string connect_label  = "Connect";
	  string disconnect_label = "Disconnect";
	//we connect to the client
     //we first check the label of the btn
	  if(connect->GetLabel() == connect_label){
	  	 client = new wxSocketClient(wxSOCKET_WAITALL);

     	 client->Connect(ip,0);
          
	  }else if(connect->GetLabel() == disconnect_label){
	  	  //we will disconnect
	  	connect->SetValue(false);
 
  		connect->SetLabel("Connect");

  		SetStatusText("Disconnected");

		}
     

}

void StreamerFrame::OnPlay(wxCommandEvent& event){
     
}
void StreamerFrame::OnStop(wxCommandEvent& event){

}
void StreamerFrame::OnPause(wxCommandEvent& event){

}
void StreamerFrame::OnAddTrack(wxCommandEvent& event){

}
void StreamerFrame::OnDelTrack(wxCommandEvent& event){

}
void StreamerFrame::OnConnectionEstablished(wxSocketEvent& event){
   
   connect->SetValue(true);

   connect->SetLabel("Disconnect");
  
   SetStatusText( "Connection Established" );

}
void StreamerFrame::OnConnectionLost(wxSocketEvent& event){
  connect->SetValue(false);
 
  connect->SetLable("Connect");

  SetStatusText("Connection to server lost");

}