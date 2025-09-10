#ifndef EP_OUTPUT_MT_H
#define EP_OUTPUT_MT_H

#ifndef SERVER
#  include "../output.h"
#else
#  include <fmt/core.h>
#endif

/**
 * Multi-threaded Output
 */

namespace OutputMt {
	template <typename FmtStr, typename... Args>
	void Info(FmtStr&& fmtstr, Args&&... args);

	void InfoStr(std::string const& msg);


	template <typename FmtStr, typename... Args>
	void Warning(FmtStr&& fmtstr, Args&&... args);

	void WarningStr(std::string const& warn);


	template <typename FmtStr, typename... Args>
	void Debug(FmtStr&& fmtstr, Args&&... args);

	void DebugStr(std::string const& msg);


	void Update();
}

#ifdef SERVER
namespace Output = OutputMt;
#endif

template <typename FmtStr, typename... Args>
inline void OutputMt::Info(FmtStr&& fmtstr, Args&&... args) {
	InfoStr(fmt::format(std::forward<FmtStr>(fmtstr), std::forward<Args>(args)...));
}

template <typename FmtStr, typename... Args>
inline void OutputMt::Warning(FmtStr&& fmtstr, Args&&... args) {
	WarningStr(fmt::format(std::forward<FmtStr>(fmtstr), std::forward<Args>(args)...));
}

template <typename FmtStr, typename... Args>
inline void OutputMt::Debug(FmtStr&& fmtstr, Args&&... args) {
	DebugStr(fmt::format(std::forward<FmtStr>(fmtstr), std::forward<Args>(args)...));
}

#endif
