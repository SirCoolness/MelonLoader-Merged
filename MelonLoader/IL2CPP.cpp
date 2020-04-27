#include "IL2CPP.h"
#include "AssertionManager.h"
#include "Mono.h"
#include "Logger.h"

HMODULE IL2CPP::Module = NULL;
Il2CppDomain* IL2CPP::Domain = NULL;
il2cpp_init_t IL2CPP::il2cpp_init = NULL;
il2cpp_add_internal_call_t IL2CPP::il2cpp_add_internal_call = NULL;
il2cpp_resolve_icall_t IL2CPP::il2cpp_resolve_icall = NULL;
il2cpp_class_from_system_type_t IL2CPP::il2cpp_class_from_system_type = NULL;
il2cpp_type_get_name_t IL2CPP::il2cpp_type_get_name = NULL;
il2cpp_class_get_name_t IL2CPP::il2cpp_class_get_name = NULL;
il2cpp_class_get_namespace_t IL2CPP::il2cpp_class_get_namespace = NULL;
il2cpp_class_get_assemblyname_t IL2CPP::il2cpp_class_get_assemblyname = NULL;
il2cpp_class_from_name_t IL2CPP::il2cpp_class_from_name = NULL;
il2cpp_class_get_method_from_name_t IL2CPP::il2cpp_class_get_method_from_name = NULL;
il2cpp_image_get_class_t IL2CPP::il2cpp_image_get_class = NULL;
il2cpp_type_get_class_or_element_class_t IL2CPP::il2cpp_type_get_class_or_element_class = NULL;
il2cpp_assembly_get_image_t IL2CPP::il2cpp_assembly_get_image = NULL;
il2cpp_domain_assembly_open_t IL2CPP::il2cpp_domain_assembly_open = NULL;
il2cpp_runtime_invoke_t IL2CPP::il2cpp_runtime_invoke = NULL;
il2cpp_class_get_nested_types_t IL2CPP::il2cpp_class_get_nested_types = NULL;
il2cpp_class_get_type_t IL2CPP::il2cpp_class_get_type = NULL;
bool IL2CPP::Setup()
{
	AssertionManager::Start("IL2CPP.cpp", "IL2CPP::Setup");

	il2cpp_init = (il2cpp_init_t)AssertionManager::GetExport(Module, "il2cpp_init");
	il2cpp_add_internal_call = (il2cpp_add_internal_call_t)AssertionManager::GetExport(Module, "il2cpp_add_internal_call");
	il2cpp_resolve_icall = (il2cpp_resolve_icall_t)AssertionManager::GetExport(Module, "il2cpp_resolve_icall");
	il2cpp_class_from_system_type = (il2cpp_class_from_system_type_t)AssertionManager::GetExport(Module, "il2cpp_class_from_system_type");
	il2cpp_type_get_name = (il2cpp_type_get_name_t)AssertionManager::GetExport(Module, "il2cpp_type_get_name");
	il2cpp_class_get_name = (il2cpp_class_get_name_t)AssertionManager::GetExport(Module, "il2cpp_class_get_name");
	il2cpp_class_get_namespace = (il2cpp_class_get_namespace_t)AssertionManager::GetExport(Module, "il2cpp_class_get_namespace");
	il2cpp_class_get_assemblyname = (il2cpp_class_get_assemblyname_t)AssertionManager::GetExport(Module, "il2cpp_class_get_assemblyname");
	il2cpp_class_from_name = (il2cpp_class_from_name_t)AssertionManager::GetExport(Module, "il2cpp_class_from_name");
	il2cpp_class_get_method_from_name = (il2cpp_class_get_method_from_name_t)AssertionManager::GetExport(Module, "il2cpp_class_get_method_from_name");
	il2cpp_image_get_class = (il2cpp_image_get_class_t)AssertionManager::GetExport(Module, "il2cpp_image_get_class");
	il2cpp_type_get_class_or_element_class = (il2cpp_type_get_class_or_element_class_t)AssertionManager::GetExport(Module, "il2cpp_type_get_class_or_element_class");
	il2cpp_assembly_get_image = (il2cpp_assembly_get_image_t)AssertionManager::GetExport(Module, "il2cpp_assembly_get_image");
	il2cpp_domain_assembly_open = (il2cpp_domain_assembly_open_t)AssertionManager::GetExport(Module, "il2cpp_domain_assembly_open");
	il2cpp_runtime_invoke = (il2cpp_runtime_invoke_t)AssertionManager::GetExport(Module, "il2cpp_runtime_invoke");
	il2cpp_class_get_nested_types = (il2cpp_class_get_nested_types_t)AssertionManager::GetExport(Module, "il2cpp_class_get_nested_types");
	il2cpp_class_get_type = (il2cpp_class_get_type_t)AssertionManager::GetExport(Module, "il2cpp_class_get_type");

	return !AssertionManager::Result;
}

void IL2CPP::AddInternalCalls()
{
	Mono::mono_add_internal_call("MelonLoader.Il2CppImports::il2cpp_init", il2cpp_init);
	Mono::mono_add_internal_call("MelonLoader.Il2CppImports::il2cpp_add_internal_call", il2cpp_add_internal_call);
	Mono::mono_add_internal_call("MelonLoader.Il2CppImports::il2cpp_resolve_icall", il2cpp_resolve_icall);
	Mono::mono_add_internal_call("MelonLoader.Il2CppImports::il2cpp_class_from_system_type", il2cpp_class_from_system_type);
	Mono::mono_add_internal_call("MelonLoader.Il2CppImports::il2cpp_type_get_name", il2cpp_type_get_name);
	Mono::mono_add_internal_call("MelonLoader.Il2CppImports::il2cpp_class_get_name", il2cpp_class_get_name);
	Mono::mono_add_internal_call("MelonLoader.Il2CppImports::il2cpp_class_get_namespace", il2cpp_class_get_namespace);
	Mono::mono_add_internal_call("MelonLoader.Il2CppImports::il2cpp_class_get_assemblyname", il2cpp_class_get_assemblyname);
	Mono::mono_add_internal_call("MelonLoader.Il2CppImports::il2cpp_class_from_name", il2cpp_class_from_name);
	Mono::mono_add_internal_call("MelonLoader.Il2CppImports::il2cpp_class_get_method_from_name", il2cpp_class_get_method_from_name);
	Mono::mono_add_internal_call("MelonLoader.Il2CppImports::il2cpp_image_get_class", il2cpp_image_get_class);
	Mono::mono_add_internal_call("MelonLoader.Il2CppImports::il2cpp_type_get_class_or_element_class", il2cpp_type_get_class_or_element_class);
	Mono::mono_add_internal_call("MelonLoader.Il2CppImports::il2cpp_assembly_get_image", il2cpp_assembly_get_image);
	Mono::mono_add_internal_call("MelonLoader.Il2CppImports::il2cpp_domain_assembly_open", il2cpp_domain_assembly_open);
	Mono::mono_add_internal_call("MelonLoader.Il2CppImports::il2cpp_runtime_invoke", il2cpp_runtime_invoke);
	Mono::mono_add_internal_call("MelonLoader.Il2CppImports::il2cpp_class_get_nested_types", il2cpp_class_get_nested_types);
	Mono::mono_add_internal_call("MelonLoader.Il2CppImports::il2cpp_class_get_type", il2cpp_class_get_type);

	static const char* namelist[] = { "il2cpp_init_utf16", "il2cpp_shutdown", "il2cpp_set_config_dir", "il2cpp_set_data_dir", "il2cpp_set_temp_dir", "il2cpp_set_commandline_arguments", "il2cpp_set_commandline_arguments_utf16", "il2cpp_set_config_utf16", "il2cpp_set_config", "il2cpp_set_memory_callbacks", "il2cpp_get_corlib", "il2cpp_alloc", "il2cpp_free", "il2cpp_array_class_get", "il2cpp_array_length", "il2cpp_array_get_byte_length", "il2cpp_array_new", "il2cpp_array_new_specific", "il2cpp_array_new_full", "il2cpp_bounded_array_class_get", "il2cpp_array_element_size", "il2cpp_class_enum_basetype", "il2cpp_class_is_generic", "il2cpp_class_is_inflated", "il2cpp_class_is_assignable_from", "il2cpp_class_is_subclass_of", "il2cpp_class_has_parent", "il2cpp_class_from_il2cpp_type", "il2cpp_class_get_element_class", "il2cpp_class_get_events", "il2cpp_class_get_fields", "il2cpp_class_get_interfaces", "il2cpp_class_get_properties", "il2cpp_class_get_property_from_name", "il2cpp_class_get_field_from_name", "il2cpp_class_get_methods", "il2cpp_class_get_parent", "il2cpp_class_get_declaring_type", "il2cpp_class_instance_size", "il2cpp_class_num_fields", "il2cpp_class_is_valuetype", "il2cpp_class_value_size", "il2cpp_class_is_blittable", "il2cpp_class_get_flags", "il2cpp_class_is_abstract", "il2cpp_class_is_interface", "il2cpp_class_array_element_size", "il2cpp_class_from_type", "il2cpp_class_get_type_token", "il2cpp_class_has_attribute", "il2cpp_class_has_references", "il2cpp_class_is_enum", "il2cpp_class_get_image", "il2cpp_class_get_rank", "il2cpp_class_get_bitmap_size", "il2cpp_class_get_bitmap", "il2cpp_stats_dump_to_file", "il2cpp_stats_get_value", "il2cpp_domain_get", "il2cpp_domain_get_assemblies", "il2cpp_exception_from_name_msg", "il2cpp_get_exception_argument_null", "il2cpp_format_exception", "il2cpp_format_stack_trace", "il2cpp_unhandled_exception", "il2cpp_field_get_flags", "il2cpp_field_get_name", "il2cpp_field_get_parent", "il2cpp_field_get_offset", "il2cpp_field_get_type", "il2cpp_field_get_value", "il2cpp_field_get_value_object", "il2cpp_field_has_attribute", "il2cpp_field_set_value", "il2cpp_field_static_get_value", "il2cpp_field_static_set_value", "il2cpp_field_set_value_object", "il2cpp_gc_collect", "il2cpp_gc_collect_a_little", "il2cpp_gc_disable", "il2cpp_gc_enable", "il2cpp_gc_is_disabled", "il2cpp_gc_get_used_size", "il2cpp_gc_get_heap_size", "il2cpp_gc_wbarrier_set_field", "il2cpp_gchandle_new", "il2cpp_gchandle_new_weakref", "il2cpp_gchandle_get_target", "il2cpp_gchandle_free", "il2cpp_unity_liveness_calculation_begin", "il2cpp_unity_liveness_calculation_end", "il2cpp_unity_liveness_calculation_from_root", "il2cpp_unity_liveness_calculation_from_statics", "il2cpp_method_get_return_type", "il2cpp_method_get_declaring_type", "il2cpp_method_get_name", "il2cpp_method_get_from_reflection", "il2cpp_method_get_object", "il2cpp_method_is_generic", "il2cpp_method_is_inflated", "il2cpp_method_is_instance", "il2cpp_method_get_param_count", "il2cpp_method_get_param", "il2cpp_method_get_class", "il2cpp_method_has_attribute", "il2cpp_method_get_flags", "il2cpp_method_get_token", "il2cpp_method_get_param_name", "il2cpp_profiler_install", "il2cpp_profiler_set_events", "il2cpp_profiler_install_enter_leave", "il2cpp_profiler_install_allocation", "il2cpp_profiler_install_gc", "il2cpp_profiler_install_fileio", "il2cpp_profiler_install_thread", "il2cpp_property_get_flags", "il2cpp_property_get_get_method", "il2cpp_property_get_set_method", "il2cpp_property_get_name", "il2cpp_property_get_parent", "il2cpp_object_get_class", "il2cpp_object_get_size", "il2cpp_object_get_virtual_method", "il2cpp_object_new", "il2cpp_object_unbox", "il2cpp_value_box", "il2cpp_monitor_enter", "il2cpp_monitor_try_enter", "il2cpp_monitor_exit", "il2cpp_monitor_pulse", "il2cpp_monitor_pulse_all", "il2cpp_monitor_wait", "il2cpp_monitor_try_wait", "il2cpp_runtime_invoke_convert_args", "il2cpp_runtime_class_init", "il2cpp_runtime_object_init", "il2cpp_runtime_object_init_exception", "il2cpp_runtime_unhandled_exception_policy_set", "il2cpp_string_length", "il2cpp_string_chars", "il2cpp_string_new", "il2cpp_string_new_len", "il2cpp_string_new_utf16", "il2cpp_string_new_wrapper", "il2cpp_string_intern", "il2cpp_string_is_interned", "il2cpp_thread_current", "il2cpp_thread_attach", "il2cpp_thread_detach", "il2cpp_thread_get_all_attached_threads", "il2cpp_is_vm_thread", "il2cpp_current_thread_walk_frame_stack", "il2cpp_thread_walk_frame_stack", "il2cpp_current_thread_get_top_frame", "il2cpp_thread_get_top_frame", "il2cpp_current_thread_get_frame_at", "il2cpp_thread_get_frame_at", "il2cpp_current_thread_get_stack_depth", "il2cpp_thread_get_stack_depth", "il2cpp_type_get_object", "il2cpp_type_get_type", "il2cpp_type_is_byref", "il2cpp_type_get_attrs", "il2cpp_type_equals", "il2cpp_type_get_assembly_qualified_name", "il2cpp_image_get_assembly", "il2cpp_image_get_name", "il2cpp_image_get_filename", "il2cpp_image_get_entry_point", "il2cpp_image_get_class_count", "il2cpp_capture_memory_snapshot", "il2cpp_free_captured_memory_snapshot", "il2cpp_set_find_plugin_callback", "il2cpp_register_log_callback", "il2cpp_debugger_set_agent_options", "il2cpp_is_debugger_attached", "il2cpp_unity_install_unitytls_interface", "il2cpp_custom_attrs_from_class", "il2cpp_custom_attrs_from_method", "il2cpp_custom_attrs_get_attr", "il2cpp_custom_attrs_has_attr", "il2cpp_custom_attrs_construct", "il2cpp_custom_attrs_free" };
	for (int i = 0; i < (sizeof(namelist) / sizeof(namelist[0])); i++)
		if (namelist[i] != NULL)
			Mono::mono_add_internal_call((std::string("MelonLoader.Il2CppImports::") + namelist[i]).c_str(), GetProcAddress(Module, namelist[i]));
}