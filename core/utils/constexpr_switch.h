#ifndef CONSTEXPR_SWITCH_H
#define CONSTEXPR_SWITCH_H

#include <utility>
#include <tuple>

namespace ks::core::utils {
    template <auto MatchValue, typename Func>
    struct Case {
        static constexpr auto value = MatchValue;
        Func func;

        template <auto Input>
        constexpr void try_run(bool& matched) const {
            if constexpr (Input == MatchValue) {
                func();
                matched = true;
            }
        }
    };

    template <auto InputValue, typename... Cs>
    struct ConstexprSwitch {
        std::tuple<Cs...> cases;

        constexpr ConstexprSwitch(Cs... cs) : cases(std::move(cs)...) {}

        template <auto MatchValue, typename Func>
        constexpr auto case_(Func func) const {
            auto new_case = std::make_tuple(Case<MatchValue, Func>{func});
            auto new_cases = std::tuple_cat(cases, new_case);

            return std::apply([]<typename... T0>(T0... args) {
                return ConstexprSwitch<InputValue, T0...>{args...};
            }, new_cases);
        }

        template <typename Func>
        constexpr void default_(Func func) const {
            bool matched = false;
            std::apply([&](const auto&... cs) {
                (cs.template try_run<InputValue>(matched), ...);
            }, cases);

            if (!matched) func();
        }
    };

    template <auto Value>
    constexpr auto constexpr_switch() {
        return ConstexprSwitch<Value>{};
    }
}

#endif //CONSTEXPR_SWITCH_H
