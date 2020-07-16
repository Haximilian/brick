// automatically generated by the FlatBuffers compiler, do not modify


#ifndef FLATBUFFERS_GENERATED_TRANSACTION_SCHEDULER_H_
#define FLATBUFFERS_GENERATED_TRANSACTION_SCHEDULER_H_

#include "flatbuffers/flatbuffers.h"

namespace Scheduler {

struct Read;
struct ReadBuilder;

struct ReadResult;
struct ReadResultBuilder;

struct Write;
struct WriteBuilder;

struct WriteStatus;
struct WriteStatusBuilder;

struct Read FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  typedef ReadBuilder Builder;
  enum FlatBuffersVTableOffset FLATBUFFERS_VTABLE_UNDERLYING_TYPE {
    VT_KEY = 4
  };
  const flatbuffers::String *key() const {
    return GetPointer<const flatbuffers::String *>(VT_KEY);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyOffset(verifier, VT_KEY) &&
           verifier.VerifyString(key()) &&
           verifier.EndTable();
  }
};

struct ReadBuilder {
  typedef Read Table;
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_key(flatbuffers::Offset<flatbuffers::String> key) {
    fbb_.AddOffset(Read::VT_KEY, key);
  }
  explicit ReadBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  flatbuffers::Offset<Read> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = flatbuffers::Offset<Read>(end);
    return o;
  }
};

inline flatbuffers::Offset<Read> CreateRead(
    flatbuffers::FlatBufferBuilder &_fbb,
    flatbuffers::Offset<flatbuffers::String> key = 0) {
  ReadBuilder builder_(_fbb);
  builder_.add_key(key);
  return builder_.Finish();
}

inline flatbuffers::Offset<Read> CreateReadDirect(
    flatbuffers::FlatBufferBuilder &_fbb,
    const char *key = nullptr) {
  auto key__ = key ? _fbb.CreateString(key) : 0;
  return Scheduler::CreateRead(
      _fbb,
      key__);
}

struct ReadResult FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  typedef ReadResultBuilder Builder;
  enum FlatBuffersVTableOffset FLATBUFFERS_VTABLE_UNDERLYING_TYPE {
    VT_STATUS = 4,
    VT_VALUE = 6
  };
  bool status() const {
    return GetField<uint8_t>(VT_STATUS, 0) != 0;
  }
  const flatbuffers::String *value() const {
    return GetPointer<const flatbuffers::String *>(VT_VALUE);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<uint8_t>(verifier, VT_STATUS) &&
           VerifyOffset(verifier, VT_VALUE) &&
           verifier.VerifyString(value()) &&
           verifier.EndTable();
  }
};

struct ReadResultBuilder {
  typedef ReadResult Table;
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_status(bool status) {
    fbb_.AddElement<uint8_t>(ReadResult::VT_STATUS, static_cast<uint8_t>(status), 0);
  }
  void add_value(flatbuffers::Offset<flatbuffers::String> value) {
    fbb_.AddOffset(ReadResult::VT_VALUE, value);
  }
  explicit ReadResultBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  flatbuffers::Offset<ReadResult> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = flatbuffers::Offset<ReadResult>(end);
    return o;
  }
};

inline flatbuffers::Offset<ReadResult> CreateReadResult(
    flatbuffers::FlatBufferBuilder &_fbb,
    bool status = false,
    flatbuffers::Offset<flatbuffers::String> value = 0) {
  ReadResultBuilder builder_(_fbb);
  builder_.add_value(value);
  builder_.add_status(status);
  return builder_.Finish();
}

inline flatbuffers::Offset<ReadResult> CreateReadResultDirect(
    flatbuffers::FlatBufferBuilder &_fbb,
    bool status = false,
    const char *value = nullptr) {
  auto value__ = value ? _fbb.CreateString(value) : 0;
  return Scheduler::CreateReadResult(
      _fbb,
      status,
      value__);
}

struct Write FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  typedef WriteBuilder Builder;
  enum FlatBuffersVTableOffset FLATBUFFERS_VTABLE_UNDERLYING_TYPE {
    VT_KEY = 4,
    VT_VALUE = 6
  };
  const flatbuffers::String *key() const {
    return GetPointer<const flatbuffers::String *>(VT_KEY);
  }
  const flatbuffers::String *value() const {
    return GetPointer<const flatbuffers::String *>(VT_VALUE);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyOffset(verifier, VT_KEY) &&
           verifier.VerifyString(key()) &&
           VerifyOffset(verifier, VT_VALUE) &&
           verifier.VerifyString(value()) &&
           verifier.EndTable();
  }
};

struct WriteBuilder {
  typedef Write Table;
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_key(flatbuffers::Offset<flatbuffers::String> key) {
    fbb_.AddOffset(Write::VT_KEY, key);
  }
  void add_value(flatbuffers::Offset<flatbuffers::String> value) {
    fbb_.AddOffset(Write::VT_VALUE, value);
  }
  explicit WriteBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  flatbuffers::Offset<Write> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = flatbuffers::Offset<Write>(end);
    return o;
  }
};

inline flatbuffers::Offset<Write> CreateWrite(
    flatbuffers::FlatBufferBuilder &_fbb,
    flatbuffers::Offset<flatbuffers::String> key = 0,
    flatbuffers::Offset<flatbuffers::String> value = 0) {
  WriteBuilder builder_(_fbb);
  builder_.add_value(value);
  builder_.add_key(key);
  return builder_.Finish();
}

inline flatbuffers::Offset<Write> CreateWriteDirect(
    flatbuffers::FlatBufferBuilder &_fbb,
    const char *key = nullptr,
    const char *value = nullptr) {
  auto key__ = key ? _fbb.CreateString(key) : 0;
  auto value__ = value ? _fbb.CreateString(value) : 0;
  return Scheduler::CreateWrite(
      _fbb,
      key__,
      value__);
}

struct WriteStatus FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  typedef WriteStatusBuilder Builder;
  enum FlatBuffersVTableOffset FLATBUFFERS_VTABLE_UNDERLYING_TYPE {
    VT_STATUS = 4
  };
  bool status() const {
    return GetField<uint8_t>(VT_STATUS, 0) != 0;
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<uint8_t>(verifier, VT_STATUS) &&
           verifier.EndTable();
  }
};

struct WriteStatusBuilder {
  typedef WriteStatus Table;
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_status(bool status) {
    fbb_.AddElement<uint8_t>(WriteStatus::VT_STATUS, static_cast<uint8_t>(status), 0);
  }
  explicit WriteStatusBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  flatbuffers::Offset<WriteStatus> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = flatbuffers::Offset<WriteStatus>(end);
    return o;
  }
};

inline flatbuffers::Offset<WriteStatus> CreateWriteStatus(
    flatbuffers::FlatBufferBuilder &_fbb,
    bool status = false) {
  WriteStatusBuilder builder_(_fbb);
  builder_.add_status(status);
  return builder_.Finish();
}

}  // namespace Scheduler

#endif  // FLATBUFFERS_GENERATED_TRANSACTION_SCHEDULER_H_