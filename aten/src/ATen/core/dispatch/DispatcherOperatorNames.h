//
// Created by Le Xu on 2020-05-02.
//
#pragma once

namespace c10 {

	class DispatcherOperatorNames final {
	private:
		DispatcherOperatorNames();
		DispatcherOperatorNames(DispatcherOperatorNames const& copy);
		DispatcherOperatorNames& operator=(DispatcherOperatorNames const & copy);
	public:
		static std::list<std::string> list;
		static DispatcherOperatorNames& singleton(){
			static DispatcherOperatorNames instance;
			return instance;
		}
	};
}