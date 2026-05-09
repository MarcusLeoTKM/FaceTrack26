#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};


#[link(name = "messages__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__messages__msg__OffsetPX() -> *const std::ffi::c_void;
}

#[link(name = "messages__rosidl_generator_c")]
extern "C" {
    fn messages__msg__OffsetPX__init(msg: *mut OffsetPX) -> bool;
    fn messages__msg__OffsetPX__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<OffsetPX>, size: usize) -> bool;
    fn messages__msg__OffsetPX__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<OffsetPX>);
    fn messages__msg__OffsetPX__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<OffsetPX>, out_seq: *mut rosidl_runtime_rs::Sequence<OffsetPX>) -> bool;
}

// Corresponds to messages__msg__OffsetPX
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct OffsetPX {

    // This member is not documented.
    #[allow(missing_docs)]
    pub offset_px: f64,

}



impl Default for OffsetPX {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !messages__msg__OffsetPX__init(&mut msg as *mut _) {
        panic!("Call to messages__msg__OffsetPX__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for OffsetPX {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { messages__msg__OffsetPX__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { messages__msg__OffsetPX__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { messages__msg__OffsetPX__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for OffsetPX {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for OffsetPX where Self: Sized {
  const TYPE_NAME: &'static str = "messages/msg/OffsetPX";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__messages__msg__OffsetPX() }
  }
}


