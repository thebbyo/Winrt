#pragma once

#include <string>
#include <vector>
#include "NoteModel.h"


class HomeViewModel {
private:
	std::vector<NoteModel> notes;
public:
	HomeViewModel();
	int GetTotalNotes() const;
	std::string GetRecentNoteTitle() const;
	void CreateNote(const std::string& title, const std::string& content);
};
