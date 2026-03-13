#include "HomeViewModel.h"
#include "pch.h"
#include "NoteModel.h"
HomeViewModel::HomeViewModel() {
	notes.push_back({ 1, "amar Note", "ja khusi tai korbo" });
	notes.push_back({ 2, "jani na", "valo manusher dam nai" });

}

int32_t HomeViewModel::GetTotalNotes() const {
	return static_cast<int32_t>(notes.size());
}

std::string HomeViewModel::GetRecentNoteTitle() const {
	if (notes.empty()) return "No Notes";

	return notes.back().title;
}


void HomeViewModel::CreateNote(const std::string& title, const std::string& content) {
	int32_t id = static_cast<int32_t>(notes.size()) + 1;
	notes.push_back({ id, title, content });
}
