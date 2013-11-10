/*
 * Copyright (C) 2013 Graeme Gott <graeme@gottcode.org>
 *
 * This library is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this library.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef WHISKERMENU_COMMAND_EDIT_H
#define WHISKERMENU_COMMAND_EDIT_H

extern "C"
{
#include <gtk/gtk.h>
}

namespace WhiskerMenu
{

class Command;

class CommandEdit
{
public:
	CommandEdit(Command* command);

	GtkWidget* get_widget() const
	{
		return m_widget;
	}

private:
	void browse_clicked();
	void command_changed();
	void shown_toggled();

private:
	Command* m_command;

	GtkWidget* m_widget;
	GtkToggleButton* m_shown;
	GtkEntry* m_entry;
	GtkWidget* m_browse_button;


private:
	static void browse_clicked_slot(GtkWidget*, CommandEdit* obj)
	{
		obj->browse_clicked();
	}

	static void command_changed_slot(GtkEditable*, CommandEdit* obj)
	{
		obj->command_changed();
	}

	static void shown_toggled_slot(GtkToggleButton*, CommandEdit* obj)
	{
		obj->shown_toggled();
	}
};

}

#endif // WHISKERMENU_COMMAND_EDIT_H
