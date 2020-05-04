////
//// Created by Le Xu on 2020-05-02.
////
#pragma once
#include <list>
#include <string>

namespace c10 {

	class CAFFE2_API DispatcherOperatorNames final {
	private:
	static std::list<std::string>* list;
	static std::mutex* mutex_;
	static int operation_count_;
//	friend class Dispatcher;
	DispatcherOperatorNames()
	{
		LOG(WARNING) << "DispatcherOperatorNames init: " << " thread id " << std::this_thread::get_id() << " pid: " << getpid();
	}
	DispatcherOperatorNames(DispatcherOperatorNames const& copy);
	DispatcherOperatorNames& operator=(DispatcherOperatorNames const & copy);

	public:
	~DispatcherOperatorNames() {};

	static DispatcherOperatorNames& singleton(){
		static DispatcherOperatorNames instance;
		return instance;
	}

	void append(std::string name){
		//std::lock_guard<std::mutex> lock(mutex_);
		mutex_->lock();
		list->emplace_back(name);
		operation_count_++;
		mutex_->unlock();
	}

	void remove(){
		mutex_ -> lock();
		operation_count_--;
		mutex_ -> unlock();
	}

	std::string readNames(){
		//std::lock_guard<std::mutex> lock(mutex_);
		mutex_->lock();
		std::string list_of_names = "List of names: ";
		for(auto  op_name : *list){
			list_of_names+= op_name ;
			list_of_names+= ",";
		}
		mutex_->unlock();
		return list_of_names;

	}

	int size(){
		int ret = 0;
		mutex_->lock();
		//std::lock_guard<std::mutex> lock(mutex_);
		ret = list->size();
		mutex_->unlock();
		return ret;
	}

};


std::list<std::string>* DispatcherOperatorNames::list = new std::list<std::string>();
std::mutex* DispatcherOperatorNames::mutex_ = new std::mutex();
int operation_count_ = 0;

}
