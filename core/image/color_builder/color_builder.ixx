export module ks.core.image.color_builder_impl:color_builder;

import ks.core.image.color_tag;
import ks.core.image.color_space;

export namespace ks::core::image {

template <color_model>
struct color_builder {
    template <color_tag>
    struct make;
};

}