/ wxWidgets "Hello world" Program
// For compilers that support precompilation, includes "wx/wx.h".
#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif
class StreamerClient: public wxApp
{
	public:
	virtual bool OnInit();
};
class StreamerFrame: public wxFrame
{
	public:
		StreamerFrame(const wxString& title, const wxPoint& pos, const wxSize& size);
	private:
		void OnConnect(wxCommandEvent& event);
		void OnDisConnect(wxCommandEvent& event);
		void OnPlay(wxCommandEvent& event);
		void OnStop(wxCommandEvent& event);
		void OnPause(wxCommandEvent& event);
		void OnAddTrack(wxCommandEvent& event);
		void OnDelTrack(wxCommandEvent& event);
		void OnShareTrack(wxCommandEvent& event);
		void OnExit(wxCommandEvent& event);
		void OnAbout(wxCommandEvent& event);
		wxButton connect*;
		wxButton play*;
		wxButton stop*; 
		wxButton pause*;
		wxButton addTrack*;
		wxButton delTrack*;
		wxButton shareTrack*;
		wxDECLARE_EVENT_TABLE();
};
enum
{
 CONNECT = 1,PLAY,STOP,PAUSE,ADDTRACK,DELTRACK,SHARETRACK
};
wxBEGIN_EVENT_TABLE(StreamerFrame, wxFrame)
EVT_BUTTON(CONNECT, StreamerFrame::OnConnect)
EVT_BUTTON(DISCONNECT, StreamerFrame::OnDisConnect)
EVT_BUTTON(PLAY, StreamerFrame::OnPlay)
EVT_BUTTON(STOP, StreamerFrame::OnStop)
EVT_BUTTON(PAUSE, StreamerFrame::OnPause)
EVT_BUTTON(ADDTRACK, StreamerFrame::OnAddTrack)
EVT_BUTTON(DELTRACK, StreamerFrame::OnDelTrack)
EVT_BUTTON(SHARETRACK, StreamerFrame::OnShareTrack)
EVT_MENU(wxID_EXIT, MyFrame::OnExit)
EVT_MENU(wxID_ABOUT, MyFrame::OnAbout)
wxEND_EVENT_TABLE()
wxIMPLEMENT_APP(StreamerClient);

bool StreamerClient::OnInit()
{
StreamerFrame *frame = new StreamerFrame( "Streamer", wxPoint(200, 400), wxSize(600, 600) );

frame->Show( true );
setTopWindow(frame);
return true;
}

MyFrame::MyFrame(const wxString& title, const wxPoint& pos, const wxSize& size)
: wxFrame(NULL, wxID_ANY, title, pos, size)
{
	//we create the various btns
    connect  = new wxButton(this, CONNECT, _T("connect"),wxPoint(5, 20), wxDefaultSize, 0);
		play  = new wxButton(this, CONNECT, _T("play"),wxPoint(5, 40), wxDefaultSize, 0);
	   stop  = new wxButton(this, CONNECT, _T("stop"),wxPoint(5, 70), wxDefaultSize, 0);
 	   pause  = new wxButton(this, CONNECT, _T("pause"),wxPoint(5, 110), wxDefaultSize, 0);
 	   addTrack = new wxButton(this, CONNECT, _T("Add track"),wxPoint(5, 140), wxDefaultSize, 0);
	delTrack = new wxButton(this, CONNECT, _T("Delete Track"),wxPoint(5, 170), wxDefaultSize, 0);
	shareTrack = new wxButton(this, CONNECT, _T("share"),wxPoint(5, 200), wxDefaultSize, 0);

}
void StreamerFrame::OnConnect(wxCommandEvent& event){

}
void StreamerFrame::OnDisconnect(wxCommandEvent& event){

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
