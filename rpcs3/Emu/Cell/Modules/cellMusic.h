#pragma once

#include "Emu/Memory/vm_ptr.h"
#include "Emu/Cell/ErrorCodes.h"
#include "cellSearch.h"

// Error Codes
enum CellMusicError : u32
{
	CELL_MUSIC_CANCELED                 = 1,
	CELL_MUSIC_PLAYBACK_FINISHED        = 0x8002c101,
	CELL_MUSIC_ERROR_PARAM              = 0x8002c102,
	CELL_MUSIC_ERROR_BUSY               = 0x8002c103,
	CELL_MUSIC_ERROR_NO_ACTIVE_CONTENT  = 0x8002c104,
	CELL_MUSIC_ERROR_NO_MATCH_FOUND     = 0x8002c105,
	CELL_MUSIC_ERROR_INVALID_CONTEXT    = 0x8002c106,
	CELL_MUSIC_ERROR_PLAYBACK_FAILURE   = 0x8002c107,
	CELL_MUSIC_ERROR_NO_MORE_CONTENT    = 0x8002c108,
	CELL_MUSIC_DIALOG_OPEN              = 0x8002c109,
	CELL_MUSIC_DIALOG_CLOSE             = 0x8002c10a,
	CELL_MUSIC_ERROR_GENERIC            = 0x8002c1ff,
};

enum CellMusic2Error : u32
{
	CELL_MUSIC2_CANCELED                = 1,
	CELL_MUSIC2_PLAYBACK_FINISHED       = 0x8002c101,
	CELL_MUSIC2_ERROR_PARAM             = 0x8002c102,
	CELL_MUSIC2_ERROR_BUSY              = 0x8002c103,
	CELL_MUSIC2_ERROR_NO_ACTIVE_CONTENT = 0x8002c104,
	CELL_MUSIC2_ERROR_NO_MATCH_FOUND    = 0x8002c105,
	CELL_MUSIC2_ERROR_INVALID_CONTEXT   = 0x8002c106,
	CELL_MUSIC2_ERROR_PLAYBACK_FAILURE  = 0x8002c107,
	CELL_MUSIC2_ERROR_NO_MORE_CONTENT   = 0x8002c108,
	CELL_MUSIC2_DIALOG_OPEN             = 0x8002c109,
	CELL_MUSIC2_DIALOG_CLOSE            = 0x8002c10a,
	CELL_MUSIC2_ERROR_GENERIC           = 0x8002c1ff,
};

enum
{
	CELL_SYSUTIL_MUSIC_INITIALIZING_FINISHED = 1,
	CELL_SYSUTIL_MUSIC_SHUTDOWN_FINISHED     = 4, // Was 3 in 1.03, changed to 4 in 1.1
	CELL_SYSUTIL_MUSIC_LOADING_FINISHED      = 5,
	CELL_SYSUTIL_MUSIC_UNLOADING_FINISHED    = 7,
	CELL_SYSUTIL_MUSIC_RELEASED              = 9,
	CELL_SYSUTIL_MUSIC_GRABBED               = 11,
};

enum
{
	CELL_SYSUTIL_MUSIC2_INITIALIZING_FINISHED = CELL_SYSUTIL_MUSIC_INITIALIZING_FINISHED,
	CELL_SYSUTIL_MUSIC2_SHUTDOWN_FINISHED     = CELL_SYSUTIL_MUSIC_SHUTDOWN_FINISHED,
	CELL_SYSUTIL_MUSIC2_LOADING_FINISHED      = CELL_SYSUTIL_MUSIC_LOADING_FINISHED,
	CELL_SYSUTIL_MUSIC2_UNLOADING_FINISHED    = CELL_SYSUTIL_MUSIC_UNLOADING_FINISHED,
	CELL_SYSUTIL_MUSIC2_RELEASED              = CELL_SYSUTIL_MUSIC_RELEASED,
	CELL_SYSUTIL_MUSIC2_GRABBED               = CELL_SYSUTIL_MUSIC_GRABBED,
};

enum
{
	CELL_MUSIC_EVENT_STATUS_NOTIFICATION          = 0,
	CELL_MUSIC_EVENT_INITIALIZE_RESULT            = 1,
	CELL_MUSIC_EVENT_FINALIZE_RESULT              = 2,
	CELL_MUSIC_EVENT_SELECT_CONTENTS_RESULT       = 3,
	CELL_MUSIC_EVENT_SET_PLAYBACK_COMMAND_RESULT  = 4,
	CELL_MUSIC_EVENT_SET_VOLUME_RESULT            = 5,
	CELL_MUSIC_EVENT_SET_SELECTION_CONTEXT_RESULT = 6,
	CELL_MUSIC_EVENT_UI_NOTIFICATION              = 7,
};

enum
{
	CELL_MUSIC2_EVENT_STATUS_NOTIFICATION          = CELL_MUSIC_EVENT_STATUS_NOTIFICATION,
	CELL_MUSIC2_EVENT_INITIALIZE_RESULT            = CELL_MUSIC_EVENT_INITIALIZE_RESULT,
	CELL_MUSIC2_EVENT_FINALIZE_RESULT              = CELL_MUSIC_EVENT_FINALIZE_RESULT,
	CELL_MUSIC2_EVENT_SELECT_CONTENTS_RESULT       = CELL_MUSIC_EVENT_SELECT_CONTENTS_RESULT,
	CELL_MUSIC2_EVENT_SET_PLAYBACK_COMMAND_RESULT  = CELL_MUSIC_EVENT_SET_PLAYBACK_COMMAND_RESULT,
	CELL_MUSIC2_EVENT_SET_VOLUME_RESULT            = CELL_MUSIC_EVENT_SET_VOLUME_RESULT,
	CELL_MUSIC2_EVENT_SET_SELECTION_CONTEXT_RESULT = CELL_MUSIC_EVENT_SET_SELECTION_CONTEXT_RESULT,
	CELL_MUSIC2_EVENT_UI_NOTIFICATION              = CELL_MUSIC_EVENT_UI_NOTIFICATION,
};

enum
{
	CELL_MUSIC_PB_CMD_STOP        = 0,
	CELL_MUSIC_PB_CMD_PLAY        = 1,
	CELL_MUSIC_PB_CMD_PAUSE       = 2,
	CELL_MUSIC_PB_CMD_NEXT        = 3,
	CELL_MUSIC_PB_CMD_PREV        = 4,
	CELL_MUSIC_PB_CMD_FASTFORWARD = 5,
	CELL_MUSIC_PB_CMD_FASTREVERSE = 6,
};

enum
{
	CELL_MUSIC2_PB_CMD_STOP        = CELL_MUSIC_PB_CMD_STOP,
	CELL_MUSIC2_PB_CMD_PLAY        = CELL_MUSIC_PB_CMD_PLAY,
	CELL_MUSIC2_PB_CMD_PAUSE       = CELL_MUSIC_PB_CMD_PAUSE,
	CELL_MUSIC2_PB_CMD_NEXT        = CELL_MUSIC_PB_CMD_NEXT,
	CELL_MUSIC2_PB_CMD_PREV        = CELL_MUSIC_PB_CMD_PREV,
	CELL_MUSIC2_PB_CMD_FASTFORWARD = CELL_MUSIC_PB_CMD_FASTFORWARD,
	CELL_MUSIC2_PB_CMD_FASTREVERSE = CELL_MUSIC_PB_CMD_FASTREVERSE,
};

enum
{
	CELL_MUSIC_PB_STATUS_STOP        = 0,
	CELL_MUSIC_PB_STATUS_PLAY        = 1,
	CELL_MUSIC_PB_STATUS_PAUSE       = 2,
	CELL_MUSIC_PB_STATUS_FASTFORWARD = 3,
	CELL_MUSIC_PB_STATUS_FASTREVERSE = 4,
};

enum
{
	CELL_MUSIC2_PB_STATUS_STOP        = CELL_MUSIC_PB_STATUS_STOP,
	CELL_MUSIC2_PB_STATUS_PLAY        = CELL_MUSIC_PB_STATUS_PLAY,
	CELL_MUSIC2_PB_STATUS_PAUSE       = CELL_MUSIC_PB_STATUS_PAUSE,
	CELL_MUSIC2_PB_STATUS_FASTFORWARD = CELL_MUSIC_PB_STATUS_FASTFORWARD,
	CELL_MUSIC2_PB_STATUS_FASTREVERSE = CELL_MUSIC_PB_STATUS_FASTREVERSE,
};

enum
{
	CELL_MUSIC_PLAYBACK_MEMORY_CONTAINER_SIZE = 11 * 1024 * 1024,
	CELL_MUSIC_PLAYER_MODE_NORMAL             = 0,
	CELL_MUSIC2_PLAYER_MODE_NORMAL            = CELL_MUSIC_PLAYER_MODE_NORMAL,
	CELL_MUSIC_SELECTION_CONTEXT_SIZE         = 2048,
};

using CellMusicCallback = void(u32 event, vm::ptr<void> param, vm::ptr<void> userData);
using CellMusic2Callback = void(u32 event, vm::ptr<void> param, vm::ptr<void> userData);

struct CellMusicSelectionContext
{
	// TODO: find out what fw does with it
	// Let's just hijack it with our own data.
	char data[CELL_MUSIC_SELECTION_CONTEXT_SIZE];
};

struct music_selection_context
{
	char magic[4] = "SUS";
	u32 content_type{0};
	u32 repeat_mode{0};
	u32 context_option{0};
	std::string path;

	static constexpr u32 max_depth = 2; // root + 1 folder + file

	bool set(const CellMusicSelectionContext& in)
	{
		if (memcmp(in.data, magic, sizeof(magic)) != 0)
		{
			return false;
		}

		u32 pos = sizeof(magic);
		memcpy(&content_type, &in.data[pos], sizeof(content_type));
		pos += sizeof(content_type);
		repeat_mode = in.data[pos++];
		context_option = in.data[pos++];
		path = &in.data[pos];

		return true;
	}

	CellMusicSelectionContext get() const
	{
		if (path.size() + 2 + sizeof(content_type) + sizeof(magic) > CELL_MUSIC_SELECTION_CONTEXT_SIZE)
		{
			fmt::throw_exception("Contents of music_selection_context are too large");
		}

		CellMusicSelectionContext out{};
		u32 pos = 0;

		std::memset(out.data, 0, CELL_MUSIC_SELECTION_CONTEXT_SIZE);
		std::memcpy(out.data, magic, sizeof(magic));
		pos += sizeof(magic);
		std::memcpy(&out.data[pos], &content_type, sizeof(content_type));
		pos += sizeof(content_type);
		out.data[pos++] = repeat_mode;
		out.data[pos++] = context_option;
		std::memcpy(&out.data[pos], path.c_str(), path.size());

		return out;
	}

	std::string to_string() const
	{
		return fmt::format("{ .magic='%s', .content_type=%d, .repeat_mode=%d, .context_option=%d, .path='%s' }", magic, content_type, repeat_mode, context_option, path);
	}

	// Helper
	error_code find_content_id(vm::ptr<CellSearchContentId> contents_id);
};
