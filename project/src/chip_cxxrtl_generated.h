#include <cxxrtl/cxxrtl.h>

#if defined(CXXRTL_INCLUDE_CAPI_IMPL) || \
    defined(CXXRTL_INCLUDE_VCD_CAPI_IMPL)
#include <cxxrtl/capi/cxxrtl_capi.cc>
#endif

#if defined(CXXRTL_INCLUDE_VCD_CAPI_IMPL)
#include <cxxrtl/capi/cxxrtl_capi_vcd.cc>
#endif

using namespace cxxrtl_yosys;

namespace cxxrtl_design {

// \top: 1
// \src: src/chip.v:1.1-10.10
struct p_chip : public module {
	// \init: 0
	// \src: src/chip.v:3.15-3.22
	wire<8> p_counter;
	// \src: src/chip.v:1.31-1.34
	/*output*/ value<1> p_led;
	// \src: src/chip.v:1.19-1.22
	/*input*/ value<1> p_clk;
	value<1> prev_p_clk;
	bool posedge_p_clk() const {
		return !prev_p_clk.slice<0>().val() && p_clk.slice<0>().val();
	}
	p_chip(interior) {}
	p_chip() {
		reset();
	};

	void reset() override;

	bool eval(performer *performer = nullptr) override;

	template<class ObserverT>
	bool commit(ObserverT &observer) {
		bool changed = false;
		if (p_counter.commit(observer)) changed = true;
		prev_p_clk = p_clk;
		return changed;
	}

	bool commit() override {
		observer observer;
		return commit<>(observer);
	}

	void debug_eval();

	void debug_info(debug_items *items, debug_scopes *scopes, std::string path, metadata_map &&cell_attrs = {}) override;
}; // struct p_chip

void p_chip::reset() {
	p_counter = wire<8>{0u};
}

bool p_chip::eval(performer *performer) {
	bool converged = true;
	bool posedge_p_clk = this->posedge_p_clk();
	// cells $procdff$4 $add$src/chip.v:6$2
	if (posedge_p_clk) {
		p_counter.next = add_uu<8>(p_counter.curr, value<1>{0x1u});
	}
	// connection
	p_led = p_counter.curr.slice<7>().val();
	return converged;
}

void p_chip::debug_eval() {
}

CXXRTL_EXTREMELY_COLD
void p_chip::debug_info(debug_items *items, debug_scopes *scopes, std::string path, metadata_map &&cell_attrs) {
	assert(path.empty() || path[path.size() - 1] == ' ');
	if (scopes) {
		scopes->add(path.empty() ? path : path.substr(0, path.size() - 1), "chip", metadata_map({
			{ "top", UINT64_C(1) },
			{ "src", "src/chip.v:1.1-10.10" },
		}), std::move(cell_attrs));
	}
	if (items) {
		items->add(path, "counter", "init\000u\000\000\000\000\000\000\000\000src\000ssrc/chip.v:3.15-3.22\000", p_counter, 0, debug_item::DRIVEN_SYNC);
		items->add(path, "led", "src\000ssrc/chip.v:1.31-1.34\000", p_led, 0, debug_item::OUTPUT|debug_item::DRIVEN_COMB);
		items->add(path, "clk", "src\000ssrc/chip.v:1.19-1.22\000", p_clk, 0, debug_item::INPUT|debug_item::UNDRIVEN);
	}
}

} // namespace cxxrtl_design

extern "C"
cxxrtl_toplevel cxxrtl_design_create() {
	return new _cxxrtl_toplevel { std::unique_ptr<cxxrtl_design::p_chip>(new cxxrtl_design::p_chip) };
}
