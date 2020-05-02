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
		std::list<std::string> list;
	public:
		static DispatcherOperatorNames& singleton(){
			static DispatcherOperatorNames instance;
			return instance;
		}

		void append(std::string name){
			list.emplace_back(name);
		}

		std::string readNames(){
			std::string list_of_names = "List of names: ";
			for(auto  op_name : DispatcherOperatorNames::singleton().list){
				list_of_names+= op_name ;
				list_of_names+= ",";
			}
			return
		}

		int size(){
			return list.size();
		}

	};
}