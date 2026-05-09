#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};



// Corresponds to messages__msg__OffsetPX

// This struct is not documented.
#[allow(missing_docs)]

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct OffsetPX {

    // This member is not documented.
    #[allow(missing_docs)]
    pub offset_px: f64,

}



impl Default for OffsetPX {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::OffsetPX::default())
  }
}

impl rosidl_runtime_rs::Message for OffsetPX {
  type RmwMsg = super::msg::rmw::OffsetPX;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        offset_px: msg.offset_px,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      offset_px: msg.offset_px,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      offset_px: msg.offset_px,
    }
  }
}


